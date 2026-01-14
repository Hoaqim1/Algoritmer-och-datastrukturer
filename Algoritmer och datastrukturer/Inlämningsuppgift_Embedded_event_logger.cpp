#include <iostream>
#include <vector>
#include <windows.h>

enum EventType {TEMP, BUTTON, MOTION};

struct Event { 
    int timestamp;
    int sensorId;
    EventType type;
    int value;
};

int global_timestamp = 0;

Event createEvent() {
    Event e;
    e.timestamp = global_timestamp++;
    e.sensorId = e.timestamp % 4;
    e.type = TEMP;
    e.value = 20 + (e.timestamp % 10);
    return e;
}

void printLog(const std::vector<Event>& log) {
    if (log.empty()) {
        std::cout << "Tom Logg" << '\n';
        return;
    }

    std::cout << "Logg " << log.size() << " event: " << '\n';
    for (int i = 0; i < (int)log.size(); i++) {
        std::cout << log[i].timestamp << '\n' << " sensor: " << log[i].sensorId << '\n' << " type: " << log[i].type << '\n' << " value: " << log[i].value << '\n';
    } 

}

int main () {
    std::vector<Event> log;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice = 0;

    do {
        std::cout << "1. Skapa ett event " << '\n';
        std::cout << "2. Utskrift av info från loggen" << '\n';
        std::cout << "3. Sortera utifrån namn" << '\n';
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
        log.push_back(e);
        std::cout << "Event skapad med ts " << e.timestamp << '\n';
            break;
            }

        case 2: 
        printLog(log);
            break;
           

        case 3:
        //sort <name>;
            break;

        case 4:
        //find <sensorId>;
            break;

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

        return 0;



    }
