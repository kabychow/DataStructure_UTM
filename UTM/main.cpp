#include "UTM.hpp"

int get_input(std::string query);
void edit(UTM *utm);

int main(int argc, const char * argv[]) {
    int length = get_input("Enter matrix length: ");
    UTM *utm_a = new UTM(length), *utm_b = new UTM(length);
    
    while (true) {
        std::cout << std::endl << std::endl << std::endl << std::endl <<
        "Matrix A: " << std::endl << utm_a->to_string() << std::endl <<
        "Matrix B: " << std::endl << utm_b->to_string() << std::endl <<
        "1. Edit Matrix A value by index" << std::endl <<
        "2. Edit Matrix B value by index" << std::endl <<
        "3. Clear Matrix A" << std::endl <<
        "4. Clear Matrix B" << std::endl <<
        "5. Sum Matrix B into Matrix A" << std::endl <<
        "6. Sum Matrix A into Matrix B" << std::endl <<
        "0. Quit" << std::endl << std::endl;
        
        switch (get_input("Select your option: ")) {
            case 1:
                edit(utm_a);
                break;
            case 2:
                edit(utm_b);
                break;
            case 3:
                utm_a->init();
                break;
            case 4:
                utm_b->init();
                break;
            case 5:
                utm_a->add(utm_b);
                break;
            case 6:
                utm_b->add(utm_a);
                break;
            case 0:
                return 0;
        }
    }
}

void edit(UTM *utm) {
    while (true) {
        try {
            int row = get_input("Enter row index to edit: ");
            int col = get_input("Enter column index to edit: ");
            int val = get_input("Enter new value: ");
            utm->at(row, col)->val = val;
            break;
        } catch (std::exception &e) {
            std::cout << "Please enter a valid index!" << std::endl;
        }
    }
}

int get_input(std::string query) {
    int out;
    while (true) {
        std::cout << query;
        if (std::cin >> out) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    }
    return out;
}
