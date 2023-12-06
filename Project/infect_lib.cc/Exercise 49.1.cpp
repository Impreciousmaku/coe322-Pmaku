#include <iostream>
#include <cstdlib>
#include <ctime>
#include "infect_lib.cc

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

    void infect(const Disease& disease);

    bool is_recovered() const {
        return state == State::Recovered;
    }
};

class Disease {
private:
    int transmissionChance;
    int daysToRecover;

public:
    Disease(int transChance, int recoverDays)
        : transmissionChance(transChance), daysToRecover(recoverDays) {}

    int get_transmission_chance() const {
        return transmissionChance;
    }

    int get_days_to_recover() const {
        return daysToRecover;
    }
};

void Person::infect(const Disease& disease) {
    if (state == State::Healthy) {
        //  random number to determine infection
        int randomChance = rand() % 100 + 1; // Generates a random number between 1 and 100
        if (randomChance <= disease.get_transmission_chance()) {
            state = State::Sick;
            daysToRecover = disease.get_days_to_recover();
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    Person joe;
    Disease flu(5, 2); // Example disease with 5% transmission chance and 2 days to recover

    for (int step = 1;; ++step) {
        joe.one_more_day();
        joe.infect(flu); // Infect Joe based on disease properties
        std::cout << "On day " << step << ", Joe is " << joe.status_string() << '\n';
        if (joe.is_recovered())
            break;
    }

    return 0;
}
