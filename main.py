import serial
import csv
from datetime import datetime, time
import os

# Replace 'COM3' with your Arduino port
ser = serial.Serial('COM3', 9600, timeout=1)
print("Waiting for attendance...")

# Directory to save file
directory = "AttendanceRecords"
if not os.path.exists(directory):
    os.makedirs(directory)

# Preloaded teacher database (same as Arduino)
teachers = {
    "T001": {"name": "John Doe", "designation": "Professor", "department": "ICI"},
    "T002": {"name": "Jane Smith", "designation": "Lecturer", "department": "DCIT"},
    "T003": {"name": "Ali Khan", "designation": "Assistant Professor", "department": "DCSE"},
    "T004": {"name": "Sara Ali", "designation": "Lecturer", "department": "ICI"},
    "T005": {"name": "Usman Khan", "designation": "Assistant Professor", "department": "DCIT"}
}

# Collect attendance in memory
attendance_data = {}

# Attendance window
end_time = time(11, 0)  # 11:00 AM

while True:
    now = datetime.now()
    
    # Read Arduino Serial
    line = ser.readline().decode().strip()
    if line:
        parts = line.split(',')
        if len(parts) >= 6:
            teacher_id = parts[0]
            status = parts[4]
            attendance_data[teacher_id] = {
                "name": parts[1],
                "designation": parts[2],
                "department": parts[3],
                "status": status,
                "time": parts[5]
            }
            print(f"Recorded: {teacher_id}, Status: {status}")
    
    # Check if time passed 11:00 AM to finalize file
    if now.time() >= end_time and attendance_data:
        date_str = now.strftime("%Y-%m-%d")
        filename = os.path.join(directory, f"Attendance_{date_str}.csv")
        
        with open(filename, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["ID","Name","Designation","Department","Present","Date","Time"])
            
            # Write all teachers, mark Absent if not in attendance_data
            for tid, info in teachers.items():
                if tid in attendance_data:
                    row = [
                        tid,
                        info['name'],
                        info['designation'],
                        info['department'],
                        attendance_data[tid]['status'],
                        date_str,
                        attendance_data[tid]['time']
                    ]
                else:
                    row = [
                        tid,
                        info['name'],
                        info['designation'],
                        info['department'],
                        "No",
                        date_str,
                        "NA"
                    ]
                writer.writerow(row)
        
        print(f"Attendance finalized. File saved: {filename}")
        break  # Stop script after final file