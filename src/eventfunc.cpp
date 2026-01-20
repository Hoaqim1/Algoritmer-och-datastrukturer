#include "eventfunc.h"
#include <iostream>

int global_timestamp = 0;

Event createEvent() {
    Event e;
    e.timestamp = global_timestamp++;
    e.sensorId = e.timestamp % 4;
    e.type = TEMP;
    e.value = 20 + (e.timestamp % 10);
    return e;
}

void printLog(const std::vector<Event>& log) {
    if (log.empty()) {
        std::cout << "Tom Logg" << '\n';
        return;
    }

    std::cout << "Logg " << log.size() << " event: " << '\n';
    for (int i = 0; i < (int)log.size(); i++) {
        std::cout << log[i].timestamp << '\n' << " sensor: " << log[i].sensorId << '\n' << " type: " << log[i].type << '\n' << " value: " << log[i].value << '\n';
    } 

}

void findSensor(const std::vector<Event>& log, int sensorId) {
    bool found = false;

    for (int i = 0; i < (int)log.size(); i++) {
        if (log[i].sensorId == sensorId) { 
        std::cout << log[i].timestamp << '\n' << " sensor: " << log[i].sensorId << '\n' << " type: " << log[i].type << '\n' << " value: " << log[i].value << '\n';
        found = true;
    }
}

    if (!found) {
        std::cout << "Inga events för " << sensorId << '\n';
        }
}