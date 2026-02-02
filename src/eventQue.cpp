#include "eventQue.h"

EventQue que_create(int capacity) {
    EventQue q;
    q.Buffer = new Event[capacity];
    q.capacity = capacity;
    q.head = 0;
    q.tail = 0;
    q.count = 0;
    return q;
}

void que_destroy(EventQue& q) {
    delete[] q.Buffer;
    q.Buffer = nullptr;
    q.capacity = 0;
    q.head = 0;
    q.tail = 0;
    q.count = 0;
}

bool que_empty(const EventQue& q) {
    return q.count == 0;
}
bool que_full(const EventQue& q) {
    return q.count == q.capacity; 
}

bool que_que(EventQue& q, Event e) {
    if (que_full(q)) {
        return false;
    }
    q.Buffer[q.head] = e;
    q.head = (q.head + 1) % q.capacity;
    q.count++;
    return true;
}

bool que_deque(EventQue& q, Event& out) {
    if (que_empty(q)) {
        return false;
    }
    out = q.Buffer[q.tail];
    q.tail = (q.tail + 1) % q.capacity;
    q.count--;
    return true;
}