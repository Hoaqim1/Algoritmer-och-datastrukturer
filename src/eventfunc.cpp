#include "eventfunc.h"
#include <iostream>

static int global_timestamp = 0;

Event createEvent() {
    Event e;
    e.timestamp = global_timestamp++;
    e.sensorId = e.timestamp % 4;
    e.type = TEMP;
    e.value = 20 + (e.timestamp % 10);
    return e;
}

SortFn getSortFn(const std::string& name) {
    if (name == "insertion") return &sortbyTS;
    return nullptr;
}

void printLog(const Eventlog& log) {
    int n = log_size(log);
    if (n == 0) {
        std::cout << "Loggen är tom" << '\n';
        return;
    }

    std::cout << "Logg " << n << '\n';
    for (int i = 0; i < n; i++) {
        Event e = log_get(log, i);
        std::cout << e.timestamp << '\n' << " Sensor: " << e.sensorId << '\n' << "Type: " << e.type << '\n' << " Värde: " << e.value << '\n';
    } 

}

void findSensor(const Eventlog& log, int sensorId) {
    bool found = false;
    int n = log_size(log);

    for (int i = 0; i < n; i++) {
        Event e = log_get(log, i);
        if (e.sensorId == sensorId) {
            std::cout << e.timestamp << '\n' << " Sensor: " << e.sensorId << '\n' << "Type: " << e.type << '\n' << " Värde: " << e.value << '\n';
        found = true;
        }
    }


    if (!found) {
        std::cout << "Inga events för " << sensorId << '\n';
        }
    }


void sortbyTS(Eventlog& log) {
    int n = log_size(log);

    for (int i = 1; i < n; i++) {
        Event key = log_get(log, i);
        int j = i - 1;

        while (j >= 0 && log_get(log, j).timestamp > key.timestamp) {
            log_set(log, j + 1, log_get(log, j));
            j--;
        }
        log_set(log, j + 1, key);
   }
}

bool sortedbyTS(const Eventlog& log) {
    int n = log_size(log);

    for (int i = 1; i < n; i++) {
        if (log_get(log, i - 1).timestamp > log_get(log, i).timestamp) {
            return false;
        }
    }
    return true;
}

void checkAlarm(Event e, AlarmSet& alarms, int threshold) {
    if (e.type == TEMP) {
        if (e.value > threshold) {
            if (!alarm_contains(alarms, e.sensorId)) {
                alarm_add(alarms, e.sensorId);
                std::cout << "alarm! Sensor " << e.sensorId << "Har triggats med värde: " << e.value << '\n';
            }
        }
            else {
                if (alarm_contains(alarms, e.sensorId)) {
                    alarm_remove(alarms, e.sensorId);
                    std::cout << "Sensor under threshold. " << e.sensorId << "Värdet är: " << e.value << '\n';
            }
        }
    }
}


