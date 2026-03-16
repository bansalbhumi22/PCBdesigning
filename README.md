# PCBdesigning
##Author
Bhumi Bansal
IIT(ISM)Dhanbad

Smart-Queue Management system
##Overview:
It is an IoT-based smart queue management system designed to manage large crowds in temples and pilgrimage sites. The system automatically counts people entering the queue using infrared sensors and controls gate mechanisms using servo motors to regulate crowd flow. The system also displays the real-time number of people in the queue on a digital display.
Crowd management systems using IoT sensors and automation can help reduce congestion and improve safety in places with high foot traffic such as temples, stadiums, and public events

##Key Features:
Real-time people counting using IR sensors
Automated gate control using servo motors
Real-time count display using TM1637 7-segment display
IoT-based hardware system using ESP32
Scalable design for multiple queue lanes
Low-cost and efficient crowd management solution

##Hardware Components:
ESP32 DevKit V1
IR Sensors
MG90S Servo Motors
TM1637 4-Digit 7-Segment Display
LM7805 Voltage Regulator
Capacitors for power filtering
DC Power Jack

##Working Principle: 
The PCB works on the principle of infrared-based people detection and microcontroller-based automated control. IR sensors detect when a person crosses the sensing area and send signals to ESP32 microcontrollers. The ESP32 processes the signal and increases the count of people. The current count is displayed on TM1637 7-segment Display. For real-time monitoring. Based on predefined values of count , ESP32 generates PWM signals to control servo-motors, which control gates or barricades. A 7805 Voltage regulator and filtering capacitors provide stable power supply.

