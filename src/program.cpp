#include <iostream>
#include <windows.h>
#include "eventfunc.h"
#include "eventLog.h"


int main () {
    Eventlog log = log_create(16);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice = 0;

    do {
        std::cout << "1. Skapa ett event " << '\n';
        std::cout << "2. Utskrift av info från loggen" << '\n';
        std::cout << "3. Sortera utifrån tid" << '\n';
        std::cout << "4. Hitta specifik sensor" << '\n';
        std::cout << "5. Hjälpfunktion" << '\n';
        std::cout << "6. Stäng av programmet." << '\n';
        
        std::cin >> choice;

        if (!std::cin) {
            std::cout << "Ogiltig inmatning" << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
    


    switch (choice){
        case 1: { 
        Event e = createEvent();
        log_append(log, e);
        std::cout << "Event skapad med ts " << e.timestamp << '\n';
            break;
            }

        case 2: 
        printLog(log);
            break;
           

        case 3:
        sortbyTS(log);
        std::cout << "Sorterad" << '\n';
        if (sortedbyTS(log)) {
            std::cout << "Check JA" << '\n';
        }
        else {
            std::cout << "Check NEJ" << '\n';
        }
            break;

        case 4: { 
        int sensId;
        std::cout << "Skriv in sensorId: ";
        std::cin >> sensId;

        if (!std::cin) {
            std::cout << "Ogiltig inmatning" << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            break;
        }
            findSensor(log, sensId);
            break;
            }

        case 5:
        //help;
            break;
        
        case 6:
        //exit;
            break;

        default:
        std::cout << "Ogiltig inmatning, välj mellan 1-6" << '\n';
        }

        } while(choice != 6);

        log_destroy(log);
        return 0;
}