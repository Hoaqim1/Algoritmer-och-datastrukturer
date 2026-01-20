#pragma once
#include <vector>

#include "event.h"

Event createEvent();
void printlog(const std::vector<Event>& log);
void findSensor(const std::vector<Event>& log, int sensorId);
void findSensor(const std::vector<Event>& log, int sensorId);
void sortTimestamp(std::vector<Event>& log);
bool isSortedTs(const std::vector<Event>& log);