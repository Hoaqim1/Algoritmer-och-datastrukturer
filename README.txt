

HOW TO RUN:
Open terminal and paste: 
g++ -std=c++17 -Wall -Wextra -Wpedantic -I .\include `
.\src\program.cpp .\src\eventfunc.cpp .\src\eventLog.cpp `
.\src\eventQue.cpp .\src\AlarmSet.cpp -o EventLogger.exe

Then you can start the app.exe or do ./EventLogger.exe 

Menu Functions
tick <n>: Do tick (whatever amount of iterations you want to run)
print: Print out log
sort <name>: Do sort insertion to sort the log. Program only uses insertion sorting
find <id>: Find (whatever sensorId you want to find)
alarms: Command to find sensors that have broken the threshold setup by the next command
setThreshold: do setThreshold (Whatever thershold you want here)
help: return to menu
exit: exit program. Does not save last session