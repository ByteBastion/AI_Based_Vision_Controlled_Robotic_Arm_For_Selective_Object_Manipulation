import os
from flask import Flask, render_template, request
import serial

app = Flask(__name__)

PORT = os.getenv("SERIAL_PORT", "COM5")
BAUD_RATE = int(os.getenv("SERIAL_BAUD", 9600))

try:
    arduino = serial.Serial(PORT, BAUD_RATE, timeout=1)
    print(f"[INFO] Connected to Arduino on {PORT} at {BAUD_RATE} baud.")
except Exception as e:
    arduino = None
    print(f"[WARNING] Could not connect to Arduino on {PORT}: {e}. Running in simulation mode.")

@app.route("/")
def home():
    return render_template("index.html")

COMMAND_MAP = {
    "left": b'B',
    "right": b'N',
    "up": b'S',
    "down": b'X',
    "forward": b'E',
    "back": b'Z',
    "open": b'H',
    "close": b'G'
}

@app.route("/move", methods=["POST"])
def move():
    direction = request.form.get("direction", "")
    cmd = COMMAND_MAP.get(direction)

    if cmd:
        if arduino and arduino.is_open:
            arduino.write(cmd)
            print(f"[ACTION] Sent command: {cmd.decode()} ({direction})")
        else:
            print(f"[SIMULATION] Mock move command: {cmd.decode()} ({direction})")
        return "OK"

    return "Invalid direction", 400

if __name__ == "__main__":
    port = int(os.getenv("PORT", 5000))
    app.run(host="0.0.0.0", port=port)