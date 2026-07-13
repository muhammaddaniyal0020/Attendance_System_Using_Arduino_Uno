# 🎓 University Teacher Attendance Registration System using Arduino UNO R3

<div align="center">

![Arduino](https://img.shields.io/badge/Arduino-UNO_R3-00979D?style=for-the-badge&logo=arduino)
![Python](https://img.shields.io/badge/Python-3.x-3776AB?style=for-the-badge&logo=python)
![Platform](https://img.shields.io/badge/Platform-Windows-blue?style=for-the-badge)
![RTC](https://img.shields.io/badge/RTC-DS3231-success?style=for-the-badge)
![LCD](https://img.shields.io/badge/LCD-16x2-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

### 📚 Smart University Teacher Attendance Management System

An intelligent **Arduino UNO R3 based Teacher Attendance Registration System** that allows university teachers to register attendance using a **4×4 Matrix Keypad**. The system verifies attendance during a specified time window, records attendance automatically in Microsoft Excel, and marks teachers absent after the attendance deadline.

</div>

---

# 📖 Project Description

The **University Teacher Attendance Registration System** is an embedded hardware and software solution designed to automate faculty attendance management in educational institutions.

Teachers enter their unique ID using a **4×4 Matrix Keypad**. The Arduino verifies the teacher information, displays the status on an LCD, provides buzzer feedback, and sends the attendance data to a Python desktop application through Serial Communication.

The Python application automatically generates a daily Excel attendance sheet containing all teachers' attendance records. Teachers who fail to register before **11:00 AM** are automatically marked **Absent**.

This project eliminates manual attendance registers, minimizes human errors, improves accuracy, and provides an efficient attendance management solution for universities.

---

# ✨ Features

- ✅ Arduino UNO R3 Based System
- ✅ Teacher ID Verification
- ✅ 4×4 Matrix Keypad Input
- ✅ 16×2 LCD Display
- ✅ Active Buzzer Notifications
- ✅ DS3231 Real-Time Clock (RTC)
- ✅ Attendance Time Window (6:00 AM – 11:00 AM)
- ✅ Automatic Present/Absent Detection
- ✅ Automatic Daily Excel File Generation
- ✅ Duplicate Attendance Prevention
- ✅ Teacher Information Database
- ✅ Department Wise Teacher Records
- ✅ Live Serial Communication
- ✅ Offline System
- ✅ Automatic Timestamp Recording
- ✅ Easy to Expand Teacher Database
- ✅ Professional Python Logging System

---

# 🏫 Departments

The system supports multiple university departments.

- Institute of Computational Intelligence (ICI)
- Department of Computer and Information Technology (DCIT)
- Department of Computer Science and Engineering (DCSE)

---

# 🛠 Hardware Requirements

| Component | Quantity |
|------------|----------|
| Arduino UNO R3 | 1 |
| 16×2 LCD Display | 1 |
| 10K Potentiometer | 1 |
| 4×4 Matrix Keypad | 1 |
| Active Buzzer | 1 |
| DS3231 RTC Module | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |
| Computer/Laptop | 1 |

---

# 💻 Software Requirements

- Arduino IDE
- Python 3.10+
- Visual Studio Code (Recommended)
- Microsoft Excel

### Python Libraries

```bash
pip install pyserial
pip install pandas
pip install openpyxl
```

---

# ⚙ Technologies Used

## Hardware

- Arduino UNO R3
- DS3231 RTC Module
- 4×4 Matrix Keypad
- 16×2 LCD Display
- Active Piezo Buzzer
- Breadboard
- USB Serial Communication

## Software

- Arduino C++
- Python
- PySerial
- Pandas
- OpenPyXL
- Microsoft Excel

---

# 🔄 Working Principle

### Step 1

Power ON the Arduino UNO.

### Step 2

LCD displays

```
Enter Teacher ID
```

### Step 3

Teacher enters their unique ID using the keypad.

Example

```
T001
```

### Step 4

Arduino searches the teacher database.

### Step 5

If the ID exists

- Teacher Name
- Designation
- Department

are verified.

### Step 6

RTC checks the current time.

If the time is between

```
06:00 AM
to
11:00 AM
```

Attendance Status

```
Present
```

Otherwise

```
Absent
```

### Step 7

LCD displays attendance status.

### Step 8

Buzzer beeps for confirmation.

### Step 9

Arduino sends attendance data to Python.

### Step 10

Python stores attendance records.

### Step 11

At exactly **11:00 AM**, a single Excel attendance sheet is generated.

### Step 12

Teachers who did not register are automatically marked

```
Absent
```

---

# 📊 Excel Output

The generated Excel file contains:

| Teacher ID | Teacher Name | Designation | Department | Status | Date | Time |
|------------|--------------|-------------|------------|--------|------|------|
| T001 | Muhammad Ali | Professor | ICI | Present | 13-07-2026 | 08:12 AM |
| T002 | Ahmed Khan | Lecturer | DCIT | Present | 13-07-2026 | 09:01 AM |
| T003 | Sara Ahmed | Assistant Professor | DCSE | Absent | 13-07-2026 | — |

The attendance file is automatically saved as:

```
Attendance_YYYY-MM-DD.xlsx
```

Example

```
Attendance_2026-07-13.xlsx
```


---

# 🔌 Circuit Connections

## Arduino UNO R3 ↔ 16×2 LCD

| LCD Pin | Arduino UNO Pin |
|----------|-----------------|
| VSS | GND |
| VDD | 5V |
| V0 | 10K Potentiometer (Center Pin) |
| RS | D7 |
| RW | GND |
| E | D8 |
| D4 | D9 |
| D5 | D10 |
| D6 | D11 |
| D7 | D12 |
| A (LED+) | 5V |
| K (LED−) | GND |

---

## Arduino UNO R3 ↔ 4×4 Matrix Keypad

| Keypad Pin | Arduino UNO Pin |
|-------------|-----------------|
| Row 1 | A0 |
| Row 2 | A1 |
| Row 3 | A2 |
| Row 4 | A3 |
| Column 1 | A4 |
| Column 2 | A5 |
| Column 3 | D2 |
| Column 4 | D4 |

---

## Arduino UNO R3 ↔ DS3231 RTC Module

| RTC Pin | Arduino UNO Pin |
|----------|-----------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

## Arduino UNO R3 ↔ Active Buzzer

| Buzzer Pin | Arduino UNO Pin |
|------------|-----------------|
| Positive (+) | D3 |
| Negative (−) | GND |

---

## Arduino UNO R3 ↔ Computer

| Connection | Description |
|------------|-------------|
| USB Type-B Cable | Serial Communication & Power Supply |

---

### Power Connections

| Arduino Pin | Connected Components |
|-------------|----------------------|
| 5V | LCD, RTC Module |
| GND | LCD, RTC Module, Buzzer |

---

# 🚀 Installation

## Clone the Repository

```bash
git clone https://github.com/muhammaddaniyal0020/Attendance_System_Using_Arduino_Uno.git
```

## Navigate to the Project

```bash
cd Attendance_System_Using_Arduino_Uno
```

## Install Required Python Libraries

```bash
pip install -r requirements.txt
```

## Upload Arduino Code

1. Open Arduino IDE.
2. Open `attendance_system.ino`.
3. Select **Arduino UNO R3**.
4. Select the correct COM Port.
5. Upload the sketch.

## Run the Python Application

```bash
python main.py
```

---

# 📈 Future Improvements

- RFID Based Authentication
- Fingerprint Authentication
- Face Recognition
- QR Code Attendance
- Cloud Database Integration
- Firebase Support
- Web Dashboard
- Mobile Application
- Wi-Fi Attendance
- Email Notifications
- SMS Notifications
- Department Analytics
- Monthly Reports
- Attendance Percentage Calculation
- AI-Based Attendance Analytics

---

# 👨‍💻 Developers

## Muhammad Daniyal

**BS Artificial Intelligence**

Institute of Computational Intelligence

Gomal University

Dera Ismail Khan, Pakistan

---

## Bushra Javed

**BS Artificial Intelligence**

Institute of Computational Intelligence

Gomal University

Dera Ismail Khan, Pakistan

---

## Dua Bukhari

**BS Artificial Intelligence**

Institute of Computational Intelligence

Gomal University

Dera Ismail Khan, Pakistan


---

# 📜 License

This project is licensed under the **MIT License**.

Feel free to use, modify, and distribute this project for educational and research purposes.

---

# ⭐ Support

If you found this project useful, please consider giving it a ⭐ on GitHub.

Your support motivates us to build more innovative embedded systems and AI-powered projects.

---

<div align="center">

### Made with ❤️ using Arduino UNO R3, Python & Microsoft Excel

**© 2026 University Teacher Attendance Registration System**

</div>
