#include "eventLog.h"

Eventlog log_create(int capacity) {
    Eventlog log;
    log.size = 0;
    log.capacity = capacity;
    log.data = new Event[capacity];
    return log;
}

void log_destroy(Eventlog& log) {
    delete[] log.data;
    log.data = nullptr;
    log.size = 0;
    log.capacity = 0;
}

int log_size(const Eventlog& log) {
    return log.size;
}

Event log_get(const Eventlog& log, int index) {
    if (index < 0) {
        return Event{};
    }
    if (index >= log.size) {
        return Event{};
    }
    return log.data[index];
}

void log_set(Eventlog& log, int index, Event e) {
    if (index < 0) {
        return;
    }
    if (index >= log.size) {
        return;
    }
    log.data[index] = e;
}

void log_append(Eventlog& log, Event e) {
    if (log.size >= log.capacity) {
        int newCap;

        if (log.capacity == 0) {
            newCap = 1;
        }
        else {
            newCap = log.capacity * 2;
        }
        Event* newData = new Event[newCap];

        for (int i = 0; i < log.size; i++) {
            newData[i] = log.data[i];
        }
        delete[] log.data;
        log.data = newData;
        log.capacity = newCap;
    }
    log.data[log.size] = e;
    log.size = log.size + 1;
}



