#pragma once

#include "event.h"
#include "eventLog.h"

Event createEvent();
void printLog(const Eventlog& log);
void findSensor(const Eventlog& log, int sensorId);
void sortbyTS(Eventlog& log);
bool sortedbyTS(const Eventlog& log);