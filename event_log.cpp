#include "event_log.h"

// Create log
EventLog* log_create(int capacity) {
    EventLog* log = new EventLog;
    log->data = new Event[capacity];
    log->size = 0;
    log->capacity = capacity;
    return log;
}

// Free memory
void log_destroy(EventLog* log) {
    delete[] log->data;
    delete log;
}

// Get size
int log_size(const EventLog* log) {
    return log->size;
}

// Add event (resize if needed)
void log_append(EventLog* log, Event e) {
    if (log->size >= log->capacity) {
        int newCap = log->capacity * 2;
        Event* newData = new Event[newCap];

        for (int i = 0; i < log->size; i++)
            newData[i] = log->data[i];

        delete[] log->data;
        log->data = newData;
        log->capacity = newCap;
    }

    log->data[log->size++] = e;
}

// Get event
Event log_get(const EventLog* log, int index) {
    return log->data[index];
}

// Replace event
void log_set(EventLog* log, int index, Event e) {
    log->data[index] = e;
}
