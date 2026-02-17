# event_logger
# Event System (C++)

This project simulates a simple event-driven system using C++.

It includes:
- Random event generation
- A circular queue (ADT)
- A dynamic event log (ADT)
- Insertion sort for sorting events
- A small alarm module that tracks high sensor values
- A menu-based interface in `main.cpp`

## How to run
1. Open the project in Visual Studio.
2. Build the solution.
3. Run the program.
4. Use the menu to:
   - Generate events (Tick)
   - Print the event log
   - Search for events by sensor ID
   - Sort the log
   - Show active alarms

## File overview
- `event.h / event.cpp` – Event structure and random event generator  
- `event_log.h / event_log.cpp` – Dynamic array for storing events  
- `queue.h / queue.cpp` – Circular queue implementation  
- `sort.h / sort.cpp` – Insertion sort (Strategy pattern)  
- `alarm_set.h / alarm_set.cpp` – Simple alarm tracking  
- `main.cpp` – Menu and program flow  

## Requirements
- Visual Studio (C++17 or later)
- Standard C++ libraries only
