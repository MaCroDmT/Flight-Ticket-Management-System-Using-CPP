# Flight-Ticket-Management-System-Using-CPP

## Overview

This is a simple **console-based Flight Ticket Management System** implemented in C++. It allows users to sign up, log in, book flight tickets, view their booked trips, and simulate payments. The system uses text files to store user credentials, flight information, and ticket bookings.

---

## Features

* **User Registration:** New users can create an account with email and password.
* **User Login:** Registered users can log in securely.
* **View Available Flights:** Displays a list of flights loaded from `flights.txt`.
* **Book Tickets:** Users can select a flight, simulate payment, and save their booking.
* **View My Trips:** Users can view all their booked flights.
* **Simple Payment Simulation:** Confirms payment before booking.

---

## File Descriptions

* **`users.txt`**
  Stores user credentials in the format:
  `email,password`

* **`flights.txt`**
  Contains available flights, each line in format:
  `FlightNo,From,To,Date,Time,Class,Price`
  Example:
  `F101,Dhaka,Chittagong,2025-06-01,08:00,Economy,2500`

* **`tickets.txt`**
  Stores booked tickets in format:
  `email,FlightNo,From,To,Date,Time,Class,Price`

---

## How to Use

1. **Sign Up** with a unique email and password if you don’t have an account.
2. **Log In** using your registered email and password.
3. **Book a Ticket** by selecting from available flights.
4. **Make Payment** by confirming the payment simulation.
5. **View My Trips** to see all your booked flights.
6. **Logout** to exit the system.

---

## How to Run

1. Make sure your `users.txt`, `flights.txt`, and `tickets.txt` files are in the same directory as the executable.

2. Compile the C++ source code using a C++ compiler, for example:

   ```bash
   g++ -o flight_system main.cpp
   ```

3. Run the program:

   ```bash
   ./flight_system
   ```

---

## Notes & Future Improvements

* Passwords are stored in plain text; consider encrypting them for better security.
* No seat availability or limits are currently managed.
* Payment is simulated without any actual transaction.
* You may want to add features like ticket cancellation, flight search filters, or GUI interface.

---

## Author: Prottoy Saha
## Self Skill Enhancement Project



---
