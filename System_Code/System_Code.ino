#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

#define buzzer 3

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7,8,9,10,11,12);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0,A1,A2,A3};
byte colPins[COLS] = {A4,A5,2,4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// RTC module
RTC_DS3231 rtc;

String teacherID = "";

// Teacher database with departments
struct Teacher {
  String id;
  String name;
  String designation;
  String department;
};

Teacher teachers[] = {
  {"T001", "John Doe", "Professor", "ICI"},
  {"T002", "Jane Smith", "Lecturer", "DCIT"},
  {"T003", "Ali Khan", "Assistant Professor", "DCSE"},
  {"T004", "Sara Ali", "Lecturer", "ICI"},
  {"T005", "Usman Khan", "Assistant Professor", "DCIT"}
};

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  
  if (!rtc.begin()) {
    lcd.print("RTC Not Found!");
    while(1);
  }
  
  lcd.print("Attendance Sys");
  delay(2000);
  lcd.clear();
  lcd.print("Enter ID:");
}

void loop() {
  char key = keypad.getKey();
  
  if(key){
    if(key == '#'){ // Confirm ID
      if(teacherID.length() > 0){
        sendAttendance(teacherID);
        teacherID = "";
      }
    }
    else if(key == '*'){ // Clear input
      teacherID = "";
      lcd.clear();
      lcd.print("Enter ID:");
    }
    else{ // Add key to ID
      teacherID += key;
      lcd.setCursor(0,1);
      lcd.print("ID: " + teacherID + "  ");
    }
  }
}

void sendAttendance(String id){
  lcd.clear();
  lcd.print("Recording...");
  
  // Read RTC time
  DateTime now = rtc.now();
  int hour = now.hour();
  int minute = now.minute();
  String timeStr = String(hour) + ":" + (minute<10?"0":"") + String(minute);

  // Determine Present or Absent based on time (6AM–11AM)
  String status = "No"; // Default Absent
  if(hour >= 6 && hour < 11){
    status = "Yes"; // Present
  }

  // Find teacher info
  String name = "";
  String designation = "";
  String dept = "";
  for(int i=0; i<sizeof(teachers)/sizeof(teachers[0]); i++){
    if(teachers[i].id == id){
      name = teachers[i].name;
      designation = teachers[i].designation;
      dept = teachers[i].department;
      break;
    }
  }
  
  if(name != ""){
    // Send record to PC
    Serial.print(id); Serial.print(",");
    Serial.print(name); Serial.print(",");
    Serial.print(designation); Serial.print(",");
    Serial.print(dept); Serial.print(",");
    Serial.print(status); Serial.print(",");
    Serial.println(timeStr);
    
    // Buzzer & LCD
    tone(buzzer, 1000, 200);
    lcd.clear();
    lcd.print("Attendance " + status);
  } else {
    lcd.clear();
    lcd.print("ID Not Found!");
    tone(buzzer, 500, 300);
  }
  
  delay(2000);
  lcd.clear();
  lcd.print("Enter ID:");
}