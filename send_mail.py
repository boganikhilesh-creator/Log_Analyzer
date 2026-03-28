import smtplib
import os

sender = "your_email@gmail.com"
receiver = "other_email@gmail.com"
password = os.getenv("EMAIL_PASS")

message = "Subject: ALERT\n\nSuspicious login activity detected!"

server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()
server.login(sender, password)
server.sendmail(sender, receiver, message)
server.quit()

print("Email Sent")
