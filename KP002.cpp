#include "MyTime.h"
#include <iostream>

int main() {
        

        std::cout << "Enter time: " << '\n';
        int h, m, s;
        std::cin >> h >> m >> s;
        MyTime time(h, m, s);
        time.print();  std::cout << '\n';
        Start:
        std::cout << "Choose an option: " << '\n';
        std::cout << "1. Add MyTime " << '\n'
            << "2. Add int (sec) " << '\n'
            << "3. Substract MyTime " << '\n'
            << "4. Substract int (sec) " << '\n'
            << "5. Mutiply " << '\n'
            << "6. Divide " << '\n'
            << "7. Add 1 sec <n> times " << '\n'
            << "8. Substract 1 sec <n> times " << '\n'
            << "9. Compare to MyTime " << '\n'
            << "10. Get hours/minutes/seconds " << '\n'
            << "11. Convert to seconds " << '\n'
            << "12. Print " << '\n';



        int option;
        std::cin >> option;
        switch (option) {
        case 1: {
            std::cout << "MyTime enter form: " << '\n'
                << "a. <hours> <minutes> <seconds> " << '\n'
                << "b. <minutes> <seconds> " << '\n'
                << "c. <seconds> " << '\n';
            char option2;
            std::cin >> option2;
            switch (option2) {
            case 'a': {
                std::cout << "Enter MyTime: <hours> <minutes> <seconds>" << '\n';
                std::cin >> h >> m >> s;
                MyTime time2(h, m, s);
                time.print();
                time = time + time2;
                std::cout << "   +   "; time2.print(); std::cout << "   =   "; time.print();
                break;
            }
            case 'b': {
                std::cout << "Enter MyTime: <minutes> <seconds>" << '\n';
                std::cin >> m >> s;
                MyTime time2(m, s);
                time.print();
                time = time + time2;
                std::cout << "   +   "; time2.print(); std::cout << "   =   "; time.print();
                break;
            }
            case 'c': {
                std::cout << "Enter MyTime: <seconds>" << '\n';
                std::cin >> s;
                MyTime time2(s);
                time.print();
                time = time + time2;
                std::cout << "   +   "; time2.print(); std::cout << "   =   "; time.print();
                break;
            }
            }
            break;
        }

        case 2: {
            int val;
            std::cout << "Enter int: " << '\n';
            std::cin >> val;
            time += val;
            time.print();
            std::cout << "   +   " << val << "   =   "; time.print();
            break;
        }

        case 3: {
            std::cout << "MyTime enter form: " << '\n'
                << "a. <hours> <minutes> <seconds> " << '\n'
                << "b. <minutes> <seconds> " << '\n'
                << "c. <seconds> " << '\n';
            char option2;
            std::cin >> option2;
            switch (option2) {
            case 'a': {
                std::cout << "Enter MyTime: <hours> <minutes> <seconds>" << '\n';
                std::cin >> h >> m >> s;
                MyTime time2(h, m, s);
                time.print();
                time = time - time2;
                std::cout << "   -   "; time2.print(); std::cout << "   =   "; time.print();
                break;
            }
            case 'b': {
                std::cout << "Enter MyTime: <minutes> <seconds>" << '\n';
                std::cin >> m >> s;
                MyTime time2(m, s);
                time.print();
                time = time - time2;
                std::cout << "   -   "; time2.print(); std::cout << "   =   "; time.print();
                break;
            }
            case 'c': {
                std::cout << "Enter MyTime: <seconds>" << '\n';
                std::cin >> s;
                MyTime time2(s);
                time.print();
                time = time - time2;
                std::cout << "   -   "; time2.print(); std::cout << "   =   "; time.print();
                break;
            }
            }
            break;
        }

        case 4: {
            int val;
            std::cout << "Enter int: " << '\n';
            std::cin >> val;
            time -= val;
            time.print();
            std::cout << "   -   " << val << "   =   "; time.print();
            break;
        }

        case 5: {
            int val;
            std::cout << "Enter int: " << '\n';
            std::cin >> val;
            time.print();
            time = val * time;
            std::cout << "   *   " << val << "   =   "; time.print();
            break;
        }

        case 6: {
            int val;
            std::cout << "Enter int: " << '\n';
            std::cin >> val;
            time.print();
            time = time / val;
            std::cout << "   /   " << val << "   =   "; time.print();
            break;
        }

        case 7: {
            int val;
            std::cout << "Enter n: " << '\n';
            std::cin >> val;
            for (int i = 0; i < val; i++) {
                time++;
                std::cout << '\n';
                time.print();
            }
            break;
        }

        case 8: {
            int val;
            std::cout << "Enter n: " << '\n';
            std::cin >> val;
            for (int i = 0; i < val; i++) {
                time--;
                std::cout << '\n';
                time.print();
            }
            break;
        }

        case 9: {
            std::cout << "MyTime enter form: " << '\n'
                << "a. <hours> <minutes> <seconds> " << '\n'
                << "b. <minutes> <seconds> " << '\n'
                << "c. <seconds> " << '\n';
            char option2;
            std::cin >> option2;
            switch (option2) {
            case 'a': {
                std::cout << "Enter MyTime: <hours> <minutes> <seconds>" << '\n';
                std::cin >> h >> m >> s;
                MyTime time2(h, m, s);
                if (time > time2) {
                    time.print(); std::cout << "   >   "; time2.print();
                }
                else if (time != time2) {
                    time.print(); std::cout << "   <   "; time2.print();
                }
                else {
                    time.print(); std::cout << "   =   "; time2.print();
                }
                break;
            }
            case 'b': {
                std::cout << "Enter MyTime: <minutes> <seconds>" << '\n';
                std::cin >> m >> s;
                MyTime time2(m, s);
                if (time > time2) {
                    time.print(); std::cout << "   >   "; time2.print();
                }
                else if (time != time2) {
                    time.print(); std::cout << "   <   "; time2.print();
                }
                else {
                    time.print(); std::cout << "   =   "; time2.print();
                }
                break;
            }
            case 'c': {
                std::cout << "Enter MyTime: <seconds>";
                std::cin >> s;
                MyTime time2(s);
                if (time > time2) {
                    time.print(); std::cout << "   >   "; time2.print();
                }
                else if (time != time2) {
                    time.print(); std::cout << "   <   "; time2.print();
                }
                else {
                    time.print(); std::cout << "   =   "; time2.print();
                }
                break;
            }
            }
            break;
        }

        case 10: {
            std::cout << "Get: " << '\n'
                << "a. hours " << '\n'
                << "b. minutes " << '\n'
                << "c. seconds " << '\n';
            char option2;
            std::cin >> option2;
            switch (option2) {
            case 'a': {
                std::cout << time[1] << '\n';
            }
            case 'b': {
                std::cout << time[2] << '\n';
            }
            case 'c': {
                std::cout << time[3] << '\n';
            }
            }
            break;
        }

        case 11: {
            time.print(); std::cout << "   =   " << time.toInt() << " seconds " << '\n';
            break;
        }

        case 12: {
            time.print();
            break;
        }

        default: {
            std::cout << "Not an option " << '\n';
            std::cout << '\n';
            goto Start;
        }

        }

        std::cout << '\n';
        goto Start;
    return 0;
}
