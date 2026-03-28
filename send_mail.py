import smtplib
import os

sender = "admin_email@gmail.com"
receiver = "user_email@gmail.com"
password = os.getenv("EMAIL_PASS")

if password is None:
    print("Error: EMAIL_PASS not set")
    exit()

message = "Subject: ALERT\n\nSuspicious login activity detected!"

server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()
server.login(sender, password)
server.sendmail(sender, receiver, message)
server.quit()

print("Email Sent")
