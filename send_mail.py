import smtplib

sender = "boganikhilesh@gmail.com"
receiver = "boganikhilesh08@gmail.com"
password = "boganikhilesh@gmail.com"

message = "Subject: ALERT\n\nSuspicious login activity detected!"

server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()
server.login(sender, password)
server.sendmail(sender, receiver, message)
server.quit()

print("Email Sent")
