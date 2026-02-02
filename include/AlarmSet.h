#pragma once

struct AlarmSet {
    int* sensors;
    int size;
    int capacity;
};

AlarmSet alarm_create(int capacity);
void alarm_destroy(AlarmSet& a);
void alarm_add(AlarmSet& a, int id);
void alarm_remove(AlarmSet& a, int id);
bool alarm_contains(AlarmSet& a, int id);