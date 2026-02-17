#include "alarm_set.h"
#include <iostream>

// Init alarm list
AlarmSet::AlarmSet() {
    size = 0;
    capacity = 5;
    alarms = new Alarm[capacity];
}

// Resize if needed
void AlarmSet::resizeIfNeeded() {
    if (size >= capacity) {
        capacity *= 2;
        Alarm* newAlarms = new Alarm[capacity];

        for (int i = 0; i < size; i++)
            newAlarms[i] = alarms[i];

        delete[] alarms;
        alarms = newAlarms;
    }
}

// Add/remove alarms
void AlarmSet::checkEvent(int sensorId, int value) {
    bool exists = false;

    for (int i = 0; i < size; i++)
        if (alarms[i].sensorId == sensorId)
            exists = true;

    if (value > threshold && !exists) {
        resizeIfNeeded();
        alarms[size++] = { sensorId, value };
    }
    else if (value <= threshold && exists) {
        for (int i = 0; i < size; i++) {
            if (alarms[i].sensorId == sensorId) {
                alarms[i] = alarms[size - 1];
                size--;
                break;
            }
        }
    }
}

// Print alarms
void AlarmSet::printAlarms() {
    if (size == 0) {
        std::cout << "No active alarms\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        std::cout << "Sensor " << alarms[i].sensorId
            << " value " << alarms[i].value << "\n";
    }
}
