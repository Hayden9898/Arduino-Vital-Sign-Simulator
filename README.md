# 🩺 Vital Sign Alert System (Simulated Embedded Monitoring)

> A simulated embedded system project inspired by Studio 1 Labs' smart fabric technology. This system mimics real-time vital sign monitoring using Arduino and basic sensors, demonstrating how biometric data can be collected, processed, and acted upon in an embedded environment.

---

![Circuit Diagram](src\circuit.PNG)

---

## 📜 Project Description

This system uses:

- A **potentiometer** to simulate heart rate (BPM)
- A **TMP36 analog sensor** to simulate body temperature (°C)
- An **LCD display** to show real-time vital sign data
- Two **LEDs** to indicate patient status:
  - 🟢 Green: Healthy range
  - 🔴 Red: Abnormal reading

It showcases how embedded systems can detect and respond to biometric trends — much like Studio 1 Labs' intelligent hospital bedding, which continuously monitors patient health.

---

## 🔧 Components Used (Tinkercad)

| Component       | Function                          |
|----------------|-----------------------------------|
| Arduino Uno     | Core microcontroller              |
| LCD 16x2        | Displays BPM and temperature      |
| Potentiometer   | Simulates heart rate (BPM)        |
| TMP36 Sensor    | Simulates body temperature        |
| Green LED       | Indicates normal vitals           |
| Red LED         | Indicates abnormal vitals         |
| Wires + Resistors | Standard connections             |

---

## 📈 Sensor Logic

- **Heart Rate Range (Simulated):** 50–150 BPM  
- **Temperature Range (Simulated):** 30–40 °C  
- **Healthy Zone:**  
  - BPM: between 50–90  
  - Temp: between 36–37°C

If values fall outside this zone, the red LED turns on to signal a warning.

---

## 💻 How It Works

- The Arduino reads analog inputs from A0 (BPM) and A1 (Temp)
- BPM is mapped from potentiometer input (0–1023 → 50–150 BPM)
- Temperature is scaled from TMP36 analog input to simulate °C values
- The LCD constantly displays the latest readings
- LEDs reflect real-time status

---

## 🧪 Simulation Instructions (Tinkercad)

1. Open the circuit in **Tinkercad Circuits**
2. Start the simulation
3. Adjust the potentiometer and TMP36 sensor values
4. Observe the LCD output and LED indicators for status

---