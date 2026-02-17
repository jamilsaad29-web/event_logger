#include <iostream>
#include <cstdlib>
#include <ctime>
#include "event.h"
#include "event_log.h"
#include "queue.h"
#include "sort.h"
#include "alarm_set.h"

// Convert enum to text
const char* eventTypeToString(EventType type) {
    switch (type) {
    case TEMP: return "TEMP";
    case BUTTON: return "BUTTON";
    case MOTION: return "MOTION";
    default: return "UNKNOWN";
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    EventLog* log = log_create(10);
    Queue* q = queue_create(5);
    AlarmSet alarms;

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1) Tick\n";
        std::cout << "2) Print log\n";
        std::cout << "3) Find sensor events\n";
        std::cout << "4) Sort log\n";
        std::cout << "5) Show alarms\n";
        std::cout << "6) Exit\n> ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int n;
            std::cout << "Ticks: ";
            std::cin >> n;

            for (int i = 0; i < n; i++) {
                Event e = make_random_event();
                queue_enqueue(q, e);
                alarms.checkEvent(e.sensorId, e.value);

                Event out;
                if (queue_dequeue(q, &out))
                    log_append(log, out);
            }
        }
        else if (choice == 2) {
            for (int i = 0; i < log_size(log); i++) {
                Event e = log_get(log, i);
                std::cout << "[" << e.timestamp << " / " << e.timestr << "] "
                    << "sensor=" << e.sensorId
                    << " type=" << eventTypeToString(e.type)
                    << " value=" << e.value << "\n";
            }
        }
        else if (choice == 3) {
            int id;
            std::cout << "Sensor ID: ";
            std::cin >> id;

            bool found = false;
            for (int i = 0; i < log_size(log); i++) {
                Event e = log_get(log, i);
                if (e.sensorId == id) {
                    found = true;
                    std::cout << "[" << e.timestamp << " / " << e.timestr << "] "
                        << "sensor=" << e.sensorId
                        << " type=" << eventTypeToString(e.type)
                        << " value=" << e.value << "\n";
                }
            }
            if (!found)
                std::cout << "No events for sensor " << id << "\n";
        }
        else if (choice == 4) {
            insertion_sort(log);
            std::cout << "Sorted.\n";
        }
        else if (choice == 5) {
            alarms.printAlarms();
        }
        else if (choice == 6) {
            break;
        }
    }

    queue_destroy(q);
    log_destroy(log);
    return 0;
}