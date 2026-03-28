# 🔐 Log Analyzer

A cybersecurity project in C that detects suspicious login attempts.

## 🚀 Features
- Multi-user authentication system
- Logs login attempts (success & failure)
- Detects suspicious activity (≥ 3 failed attempts)
- Identifies unknown users
- Email alert system (Python integration)

## 🛠 Technologies Used
- C Programming
- File Handling
- Git & GitHub
- Python (for email alerts)

## ▶️ How to Run
1. Compile:
   gcc Project.c -o run
2. Execute:
   ./run
## 🧠 How It Works

- User enters login credentials
- System validates against stored accounts
- Logs all attempts in a file
- Analyzes failed attempts
- Flags suspicious users (≥ 3 failures)
- Sends email alert (optional)

## 🔐 Security Note

This project simulates basic authentication and logging.
Passwords are stored in plain text for demonstration purposes only.
In real systems, passwords should be hashed.

## 📊 Example Output
Suspicious users are flagged after multiple failed attempts.
