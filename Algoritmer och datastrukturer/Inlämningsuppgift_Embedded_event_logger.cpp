#include <iostudio>

int main () {

    int choice;

    do {
        std::cout << "1. Skapa ett event " << '\n';
        std::cout << "2. Utskrift av info från loggen" << '\n';
        std::cout << "3. Sortera utifrån namn" << '\n';
        std::cout << "4. Hitta specifik sensor" << '\n';
        std::cout << "5. Hjälpfunktion" << '\n';
        std::cout << "6. Stäng av programmet.";
        
        std::cin >> choice 

        if (!std::cin) {
            std::cout << "Ogiltig inmatning" << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
    }


    switch (choice){
        case 1:
        tick <n>
            break;

        case 2:
        print latest n;
            break;

        case 3:
        sort <name>;
            break;

        case 4:
        find <sensorId>;
            break;

        case 5:
        help;
            break;
        
        case 6:
        exit;
            break;

        default:
        std::cout << "Ogiltig inmatning, välj mellan 1-6" << '\n';
        }

        { while(choice != 6);




    }
}