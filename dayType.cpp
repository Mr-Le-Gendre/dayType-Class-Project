#include "dayType.h"
#include <iostream>

const std::string dayType::daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

dayType::dayType() {
    day = "Sunday";
}

dayType::dayType(const std::string& day) {
    this->day = day;
}

void dayType::setDay(const std::string& day) {
    this->day = day;
}

void dayType::printDay() const {
    std::cout << day;
}

std::string dayType::getDay() const {
    return day;
}

std::string dayType::getNextDay() const {
    int idx = 0;
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            idx = i;
            break;
        }
    }
    return daysOfWeek[(idx + 1) % 7];
}

std::string dayType::getPrevDay() const {
    int idx = 0;
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            idx = i;
            break;
        }
    }
    return daysOfWeek[(idx + 6) % 7];
}

void dayType::addDays(int numDays) {
    int idx = 0;
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            idx = i;
            break;
        }
    }
    idx = (idx + numDays) % 7;
    if (idx < 0) idx += 7;
    day = daysOfWeek[idx];
}

// Add the main function here
int main() {
    dayType day("Monday");
    std::cout << "The day is: ";
    day.printDay();
    std::cout << "\nThe next day is: " << day.getNextDay();
    std::cout << "\nThe previous day is: " << day.getPrevDay();
    day.addDays(3);
    std::cout << "\nThree days later, it will be: ";
    day.printDay();
    std::cout << '\n';
    return 0;
}
