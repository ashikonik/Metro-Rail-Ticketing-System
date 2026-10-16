# 🚇 Dhaka Metro Rail Ticketing & Passenger Management System

[![Language: C](https://img.shields.io/badge/Language-C99-00599C?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![IDE: Code::Blocks](https://img.shields.io/badge/IDE-Code%3A%3ABlocks-2196F3?style=flat-square)](http://www.codeblocks.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=flat-square&logo=windows)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/License-Academic-lightgrey?style=flat-square)](#-license)

> **East West University** · Department of Computer Science & Engineering  
> Console-based Ticket Vending & Passenger Transit Simulation

---

## 👥 Development Team

| Name | Role | Student ID |
|---|---|---|
| **Shahriar Mahabub Oishik** | Team Lead & Backend Developer | `2023-3-60-073` |
| **Pulok Akibuzzaman** | Frontend & Terminal UI Developer | `2023-3-60-051` |
| **Md. Ashik-Uz-Zaman** | Debugger & System Quality Engineer | `2023-3-60-074` |

---

## 📌 Project Overview

The **Dhaka Metro Rail Ticketing System** is an interactive, console-driven application developed in C that models the ticketing, smart pass, and passenger management operations of the Dhaka Mass Rapid Transit (MRT) network.

Designed to emulate physical Ticket Vending Machines (TVMs) and automated turnstile fare gates, the system provides a complete workflow for single-journey passengers and registered MRT pass holders, featuring custom ANSI/coordinate-based ASCII UI rendering, fare calculation algorithms, and flat-file database persistence.

---

## 🌟 Core Features

### 1. 🎫 Single Journey Tickets (PreTicket & Ticket Issuance)
- **Origin & Destination Selection:** Real-time lookup of operational stations across the MRT line.
- **Dynamic Fare Calculation:** Automatically computes fare based on travel distance and station count (`PER_STATION_FEE`).
- **Cryptographic UID Generation:** Generates unique, non-colliding 8-character alphanumeric ticket IDs.
- **Validity & Expiry Management:** Enforces departure date, purchase timestamp, and validity windows.

### 2. 💳 MRT Pass / Membership System
- **Member Registration:** Creation of passenger transit accounts with contact details and masked password credentials.
- **Masked Password Security:** Custom interactive credential input supporting masked asterisks (`*`) and backspace correction.
- **Balance Inquiries & Recharge:** Real-time card balance lookups and account credit top-ups.
- **Automated Gate Simulation:** Deducts travel fare from card balance upon tapping through turnstile gates.

### 3. 🗺️ Network Information & Timetable
- **Station Directory:** Interactive list of stations, station codes, and line distances.
- **Service Timetables:** Scheduled train departures, operating hours, and travel intervals.

### 4. 💾 Flat-File Database Engine
- Zero external DBMS dependencies.
- Structured, comma-separated database files with automatic file parsing and record appending.

---

## 🏛️ System Architecture & Codebase Layout

```
Metro-Rail-Ticketing-System/
├── Metro Rail Ticketing System/
│   ├── main.c                          # Main event loop, menu navigation, state dispatch
│   ├── DataTypes.h                     # Data structs (Ticket, Member, PreTicket, MemberTicket)
│   ├── UserInterface.h                 # ASCII banners, interactive menu layouts, UI screens
│   ├── SpecialFunction.h               # Fare calculation, UID generator, masked input, date/time
│   ├── R_W.h                           # File I/O routines for reading and writing database records
│   ├── Block.h                         # Cursor positioning (MoveCursor), line drawing, directional arrows
│   ├── Database/                       # Plain-text persistent record storage
│   │   ├── MemberDBS.txt               # Registered transit cardholder accounts
│   │   ├── TicketDBS.txt               # Active issued tickets
│   │   └── PreTicketDBS.txt            # Pre-booked and pending transit tickets
│   ├── Metro Rail Ticketing System.cbp # Code::Blocks project configuration
│   └── Metro_Rail_Ticketing_System.docx# Comprehensive project documentation & report
└── README.md
```

### Module Responsibilities

| Header / Source | Description |
|---|---|
| [`DataTypes.h`](<Metro Rail Ticketing System/DataTypes.h>) | Defines core data structures: `Ticket`, `Member`, `MemberTicket`, `PreTicket`. |
| [`SpecialFunction.h`](<Metro Rail Ticketing System/SpecialFunction.h>) | Provides `PasswordInput()` (masked input), `TFare()` (fare computation), `getTime()`, and station converters. |
| [`R_W.h`](<Metro Rail Ticketing System/R_W.h>) | Handles file parsing (`DReadTic()`, `DReadMemb()`, `DReadPreTic()`) and persistent writes (`DWriteTic()`, etc.). |
| [`UserInterface.h`](<Metro Rail Ticketing System/UserInterface.h>) | Renders screen views: `HomePage()`, `BuyPreTicket()`, `MemberRegistration()`, and route menus. |
| [`Block.h`](<Metro Rail Ticketing System/Block.h>) | Low-level coordinate cursor positioning using Windows Console API (`SetConsoleCursorPosition`). |

---

## 📊 Data Structures

```c
struct Ticket {
    char UID[9];        // 8-character unique alphanumeric identifier
    char name[30];      // Passenger name
    char PNum[12];      // Phone number
    char DOP[31];       // Date of purchase
    char DOE[31];       // Date of expiry
    char DCode[4];      // Destination station code
};

struct Member {
    char name[30];      // Member full name
    char PNum[12];      // Registered phone number
    char Password[27];  // Account security credential
    int Balance;        // Current smart card credit balance (BDT)
};
```

---

## 🛠️ Build & Execution Guide

### Prerequisites
- Windows OS (relies on Windows console headers: `windows.h`, `conio.h`)
- **Code::Blocks IDE** with MinGW (recommended) or standalone **GCC / MinGW**

### Option A: Using Code::Blocks IDE
1. Open Code::Blocks.
2. Go to **File** → **Open...** and select `Metro Rail Ticketing System/Metro Rail Ticketing System.cbp`.
3. Press **F9** (Build & Run) or click the **Build and run** button.

### Option B: Using Command Line (MinGW / GCC)
1. Open Command Prompt or PowerShell in the `Metro Rail Ticketing System` directory:
   ```cmd
   cd "Metro Rail Ticketing System"
   ```
2. Compile the application:
   ```cmd
   gcc -Wall -Wextra main.c -o "MetroRail.exe"
   ```
3. Run the compiled executable:
   ```cmd
   MetroRail.exe
   ```

> [!NOTE]
> For optimal rendering of the ASCII user interface, configure your terminal window buffer width to at least 150 columns and font to a monospace typeface (such as Consolas or Cascadia Code).

---

## 📄 License

This project was developed as an academic term project for coursework at **East West University**. All rights belong to the contributing authors.
