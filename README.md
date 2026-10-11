<div align="center">
  <img src="robotic_arm_illustration.jpg" alt="Vision-Controlled Robotic Arm - Computer Vision and Hardware Interaction" width="100%">
  
  # AI-Based Vision-Controlled Robotic Arm for Selective Object Manipulation
  
  <p align="center">
    <img src="https://img.shields.io/badge/Python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54" alt="Python" />
    <img src="https://img.shields.io/badge/OpenCV-%23white.svg?style=for-the-badge&logo=opencv&logoColor=white" alt="OpenCV" />
    <img src="https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white" alt="Arduino" />
    <img src="https://img.shields.io/badge/YOLO-FF1493?style=for-the-badge&logo=yolo&logoColor=white" alt="YOLO" />
  </p>
  
  <p align="center">
    <a href="https://github.com/TechBastards/AI_Based_Vision_Controlled_Robotic_Arm_For_Selective_Object_Manipulation">
      <img src="https://github-readme-stats.vercel.app/api/pin/?username=TechBastards&repo=AI_Based_Vision_Controlled_Robotic_Arm_For_Selective_Object_Manipulation&theme=tokyonight&hide_border=true" alt="Robotic Arm Repo Stats" />
    </a>
  </p>
</div>
AI-powered vision-controlled robotic arm capable of real-time object detection, classification, and selective pick-and-place manipulation using computer vision and motion planning. The system integrates deep learning-based perception with precise robotic control to autonomously identify and handle objects in dynamic environments. An intelligent robotic system that integrates **computer vision, deep learning, and embedded systems** to enable **real-time object detection and autonomous pick-and-place operations**.

This project demonstrates an end-to-end pipeline where visual input is processed using AI models, translated into spatial coordinates, and executed through a robotic arm for precise object manipulation.

---

## Project Overview

Traditional robotic systems rely on predefined instructions and lack adaptability to dynamic environments.

This project solves that limitation by introducing:

* Real-time object detection using AI
* Intelligent selection of target objects
* Automatic coordinate mapping
* Autonomous robotic arm movement

The system bridges the gap between **perception (vision)** and **action (robotics)**.

---

## Problem Statement

Conventional robotic arms:

* Cannot identify objects autonomously
* Require manual programming for each task
* Lack flexibility in dynamic environments

This project addresses these issues by creating a **vision-guided robotic system** capable of making decisions based on real-time visual input.

---

##  Solution Approach

The system is divided into multiple stages:

1.  Capture live video using camera
2.  Detect objects using YOLOv8
3.  Filter selected objects (selective detection)
4.  Extract object coordinates
5.  Map image coordinates to real-world space
6.  Send commands to Arduino-controlled robotic arm

---

###  Pipeline Flow

```
Camera → Object Detection → Selective Filtering → Coordinate Extraction → Mapping → Robotic Arm Execution
```
---

##  Project Structure

```
AI-Vision-Robotic-Arm/
│
├── AppProject/                     # Web interface (Flask-based)
│   ├── app.py                     # Main application server
│   └── templates/
│       └── index.html             # Frontend UI
│
├── Documents/
│   └── Images/                    # Project visuals & diagrams
│       ├── 3D_Model_Creation_on_AutoDesk_Fusion360.png
│       ├── Blue_Print_of_Robotic_Arm.png
│       ├── Object_Detection_using_OpenCV.png
│       ├── Robotic_Arm.png
│       └── Robotic_Arm_Circuit_Diagram.png
│
├── Phase_1_camera_test/           # Camera initialization & testing
│   └── CameraTest.py
│
├── Phase_2_yolo_detection/        # Basic YOLO object detection
│   ├── Yolo_Basics.py
│   └── yolov8n.pt                 # Pre-trained YOLO model
│
├── Phase_3_selective_detection/   # Selective object filtering
│   └── yolo_selective.py
│
├── Phase_4_coordinate_extraction/ # Extract object coordinates
│   ├── yolo_with_coordinates.py
│   └── yolov8n.pt
│
├── Phase_5_mapping/               # Map coordinates to robotic arm
│   ├── yolo_with_mapping.py
│   └── yolov8n.pt
│
├── Robotic_Arm_Arduino_Code/      # Arduino control logic
│   └── Robotic_Arm_Arduino_Code.ino
│
├── .gitignore
└── README.md
```

---

##  Tech Stack

| Technology           | Purpose             |
| -------------------- | ------------------- |
| Python               | Core development    |
| OpenCV               | Image processing    |
| YOLOv8 (Ultralytics) | Object detection    |
| Flask                | Web interface       |
| Arduino              | Robotic arm control |
| Fusion 360           | 3D design           |

---

##  How to Run

### 1️ Clone the Repository

```
git clone https://github.com/TechBastards/AI_Based_Vision_Controlled_Robotic_Arm_For_Selective_Object_Manipulation.git
cd AI_Based_Vision_Controlled_Robotic_Arm_For_Selective_Object_Manipulation
```

### 2️ Install Dependencies

```
pip install -r requirements.txt
```

### 3️ Run the Web Interface

```bash
# Optional: Set custom serial port (default: COM5)
# set SERIAL_PORT=COM5 (Windows) or export SERIAL_PORT=/dev/ttyUSB0 (Linux)
python AppProject/app.py
```

---

## 🔧 Arduino Setup

1. Open the Arduino sketch:

```
Robotic_Arm_Arduino_Code/Robotic_Arm_Arduino_Code.ino
```

2. Select your board (e.g., Arduino Mega / Uno) in the Arduino IDE.

3. Select your serial port and upload the sketch.

---

##  Key Features

* Real-time AI-based object detection
* Selective object targeting
* Coordinate extraction & mapping
* Autonomous robotic arm movement
* Integrated vision-to-action pipeline
* Web-based control interface

---

##  Future Improvements

* Multi-object tracking
* Depth estimation for better accuracy
* Reinforcement learning for grasping
* Edge deployment (Raspberry Pi / Jetson Nano)
* Performance optimization

---

##  Learnings

* Integration of AI with robotics systems
* Real-time data processing challenges
* Coordinate transformation techniques
* Hardware-software communication

---

##  Author

**Vinayak Sharma** &
**Harsh Singh**

* [GitHub (Vinayak Sharma)](https://github.com/TechBastards)
* [LinkedIn (Vinayak Sharma)](https://www.linkedin.com/in/vinayak-sharma-24a8aa384/)

* [GitHub (Harsh Singh)](https://github.com/Harsh0012-ux)
* [LinkedIn (Harsh Singh)](https://www.linkedin.com/in/harsh-singh-516611295/)
---
