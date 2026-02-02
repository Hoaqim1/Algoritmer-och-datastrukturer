#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include "eventfunc.h"
#include "eventLog.h"
#include "eventQue.h"
#include "AlarmSet.h"

void help() {
    std::cout << "tick <n>" << '\n';
    std::cout << "print" << '\n';
    std::cout << "sort <name>" << '\n';
    std::cout << "find <id>" << '\n';
    std::cout << "alarms" << '\n';
    std::cout << "setThreshold <n>" << '\n';
    std::cout << "help" << '\n';
    std::cout << "exit" << '\n';
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Eventlog log = log_create(16);
    EventQue q = que_create(8);

    AlarmSet alarms = alarm_create(4);
    int threshold = 25;

    help();

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "exit") {
            break;
        }
        else if (cmd == "help") {
            help();
        }
        else if (cmd == "print") {
            printLog(log);
        }
        else if (cmd == "find") {
            int id;
            if (iss >> id) findSensor(log, id);
            else std::cout << "find <id>" << '\n';
        }
        else if (cmd == "sort") {
            std::string name;
            if (!(iss >> name)) {
                std::cout << "sort <name>" << '\n';
                continue;
            }

            SortFn fn = getSortFn(name);
            if (fn) fn(log);
            else std::cout << "okänd sort" << '\n';
        }
        else if (cmd == "tick") {
            int n;
            if (!(iss >> n)) {
                std::cout << "tick <n>" << '\n';
                continue;
            }

            for (int i = 0; i < n; i++) {
                Event e = createEvent();
                que_que(q, e);

                Event out;
                if (que_deque(q, out)) {
                    checkAlarm(out, alarms, threshold);
                    log_append(log, out);
                }
            }

            std::cout << "okej" << '\n';
        }

        else if (cmd == "alarms") {
            if (alarms.size == 0) {
                std::cout << "Inga alarm" << '\n';
            } 
            else {
                std::cout << "Alarm: ";
                for (int i = 0; i < alarms.size; i++) {
                    std::cout << alarms.sensors[i] << " ";
                }
                                std::cout << '\n';
            }
        }

        else if (cmd == "setThreshold") {
            int newThreshold;
            if (iss >> newThreshold) {
                threshold = newThreshold;
                std::cout << "Threshold: " << threshold << '\n';
            }
            else {
                std::cout << "setThreshold <n>" << '\n';
        }
    }

        else {
            std::cout << "Ogiltig Inmatning" << '\n';
        }
    }
    

    que_destroy(q);
    log_destroy(log);
    alarm_destroy(alarms);
    return 0;
}
