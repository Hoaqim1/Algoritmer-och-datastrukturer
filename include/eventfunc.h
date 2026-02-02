#pragma once

#include "event.h"
#include "eventLog.h"
#include "AlarmSet.h"
#include <string>

using SortFn = void(*)(Eventlog& log);

Event createEvent();
void printLog(const Eventlog& log);
void findSensor(const Eventlog& log, int sensorId);
void sortbyTS(Eventlog& log);
bool sortedbyTS(const Eventlog& log);
SortFn getSortFn(const std::string& name);
void checkAlarm(Event e, AlarmSet& alarms, int threshold);
