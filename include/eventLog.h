#pragma once
#include "event.h"

struct Eventlog {
    Event* data;
    int size;
    int capacity;
};

Eventlog log_create(int capacity);

void log_destroy(Eventlog& log);

int log_size(const Eventlog& log);
Event log_get(const Eventlog& log, int index);
void log_set(Eventlog& log, int index, Event e);
void log_append(Eventlog& log, Event e);