#include "event.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

static int globalTime = 0; // Unique timestamp counter

Event make_random_event() {
    Event e;
    e.timestamp = ++globalTime;
    e.sensorId = rand() % 5;
    e.type = static_cast<EventType>(rand() % 3);
    e.value = rand() % 100;

    // Format time as HH:MM:SS
    int seconds = globalTime % 60;
    int minutes = (globalTime / 60) % 60;
    int hours = (globalTime / 3600) % 24;

    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    e.timestr = ss.str();
    return e;
}