#ifndef ALARM_SET_H
#define ALARM_SET_H

// Tracks active alarms
class AlarmSet {
public:
    AlarmSet();
    void checkEvent(int sensorId, int value);
    void printAlarms();

private:
    struct Alarm {
        int sensorId;
        int value;
    };

    Alarm* alarms;
    int size;
    int capacity;
    const int threshold = 80;

    void resizeIfNeeded();
};

#endif
