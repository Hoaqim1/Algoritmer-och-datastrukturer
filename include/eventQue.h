#pragma once
#include "event.h"

struct EventQue {
    Event* Buffer;
    int capacity;
    int head;
    int tail;
    int count;
};

EventQue que_create(int capacity);
void que_destroy(EventQue& q);
bool que_empty(const EventQue& q);
bool que_full(const EventQue& q);
bool que_que(EventQue& q, Event e);
bool que_deque(EventQue& q, Event& out);