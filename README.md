# 🛗 Flexible Elevator Simulation (C++)

A simple and configurable multithreaded elevator simulation written in pure C++.  
The system simulates how an elevator reacts to incoming signals from various floors and processes them accordingly.

---

## ✨ Main Functionalities

### 📶 Dynamic Floor Signals
- ✅ The elevator accepts input from multiple floors.
- ✅ Floor count is flexible – can be changed by modifying a single constant in the source code.
- ✅ Each signal is processed by a dedicated thread.

### 🔄 Threaded Execution
- ✅ Simulates concurrent requests from different floors.
- ✅ Handles requests sequentially, depending on elevator position and direction.
- ⚠️ Basic protection is included against thread collisions (race conditions are rare, but possible).

### 🧮 Data Handling
- 📥 Accepts user input from the console
- 📌 Works with:
  - Integers (`int`) – for floor numbers
  - Characters (`char`) – for user choices or signals

---

## ⚠️ Known Limitations & Error Handling

- 🚧 Possible error: submitting a non-integer when a floor number is expected (e.g., char instead of int)
- 🧵 Rare thread overlapping issues may occur (thread safety is handled to a basic level)
- 🔢 User input validation is minimal – designed for demonstration/testing purposes

---

## 🛠️ Technologies Used

- 💻 Language: **C++**
- 🧵 Multithreading: **`std::thread`**, **`mutex`**
- 📟 Input/Output: **Standard console I/O**

---

## 📽️ Demo

_A short demo GIF showcasing how the elevator simulation runs will appear here._

![Elevator](https://github.com/user-attachments/assets/3271a583-0f13-4b72-aaf8-93e70c12b982)
