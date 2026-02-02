#include "AlarmSet.h"

AlarmSet alarm_create(int capacity) {
    AlarmSet a;
    a.size = 0;
    a.capacity = capacity;
    a.sensors = new int[capacity];
    return a;
}

void alarm_destroy(AlarmSet& a) {
    delete[] a.sensors;
    a.sensors = nullptr;
    a.size = 0;
    a.capacity = 0;
}

bool alarm_contains(AlarmSet& a, int id) {
    for (int i = 0; i < a.size; i++) {
        if (a.sensors[i] == id) {
            return true;
        }
    }
            return false;
}

void alarm_add(AlarmSet& a, int id) {
    if (alarm_contains(a, id)) {
        return;
    }
    if (a.size >= a.capacity) {
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < a.size; i++) {
            newData[i] = a.sensors[i];
        }
        delete[] a.sensors;
        a.sensors = newData;
        a.capacity = newCapacity;
    }
    a.sensors[a.size] = id;
    a.size++;
}

void alarm_remove(AlarmSet& a, int id) {
    for (int i = 0; i < a.size; i++) {
        if (a.sensors[i] == id) {
            a.sensors[i] = a.sensors[a.size - 1];
            a.size--;
            return;
        }
    }
}

