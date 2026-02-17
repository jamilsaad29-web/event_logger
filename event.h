#ifndef EVENT_H
#define EVENT_H

#include <string>

// Event types
typedef enum { TEMP, BUTTON, MOTION } EventType;

// Event structure
typedef struct {
    int timestamp;
    std::string timestr;
    int sensorId;
    EventType type;
    int value;
} Event;

// Creates a random event
Event make_random_event();

#endif

