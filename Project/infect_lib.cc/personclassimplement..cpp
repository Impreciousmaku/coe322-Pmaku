#include <iostream>
#include <string>
#include "infect_lib.cc
#include "infect_lib.cc

// Forward declaration of Disease class
class Disease;

class Person {
private:
    enum class State { Healthy, Sick, Recovered, Vaccinated };
    State state;
    int daysToRecover;

public:
    Person() : state(State::Healthy), daysToRecover(0) {}

    std::string status_string() const {
        switch (state) {
        case State::Healthy:
            return "healthy";
        case State::Sick:
            return "sick (" + std::to_string(daysToRecover) + " days to go)";
        case State::Recovered:
            return "recovered";
        case State::Vaccinated:
            return "vaccinated";
        default:
            return "unknown";
        }
    }

    void one_more_day() {
        if (state == State::Sick) {
            daysToRecover--;
            if (daysToRecover == 0) {
                state = State::Recovered;
            }
        }
    }

    // infect method
    void infect(const Disease& disease);

    //  method to set the person's state to Vaccinated
    void vaccinate() {
        state = State::Vaccinated;
    }
};

// Define the Disease class
class Disease {
public:

};

// Implement the infect method for the Person class
void Person::infect(const Disease& disease) {
    // how  to handle infection based on the disease
    // a person gets sick for 5 days
    state = State::Sick;
    daysToRecover = 5;
}

int main() {
    // instances of Person and Disease
    Person person;
    Disease disease;

    // Infect the person
    person.infect(disease);

    // Display the initial status
    std::cout << "Initial status: " << person.status_string() << std::endl;

    // Simulate the progression of time
    for (int day = 1; day <= 5; ++day) {
        person.one_more_day();
        std::cout << "Day " << day << " status: " << person.status_string() << std::endl;
    }

    return 0;
}




