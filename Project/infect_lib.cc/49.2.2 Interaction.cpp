#include <iostream>
#include <cstdlib>
#include <ctime>
#include "infect_lib.cc

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

    bool transmit() const {
        // Simulate transmission based on the chance
        return (rand() % 100) < transmissionChance;
    }
};

class Person {
private:
    enum class State { Healthy, Sick, Recovered, Vaccinated };
    State state;
    int daysToRecover;

public:
    Person() : state(State::Healthy), daysToRecover(0) {}

    std::string status_string() const {
        // ... (unchanged)
    }

    void one_more_day() {
        // ... (unchanged)
    }

    void infect(const Disease& disease);

    bool is_recovered() const {
        return state == State::Recovered;
    }
};

void Person::infect(const Disease& disease) {
    if (state == State::Healthy && disease.transmit()) {
        state = State::Sick;
        daysToRecover = disease.get_days_to_recover();
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    Person joe;
    Disease flu(5, 2); // Example disease with 5% transmission chance and 2 days to recover

    for (int step = 1;; ++step) {
        joe.one_more_day();
        joe.infect(flu);
        std::cout << "On day " << step << ", Joe is " << joe.status_string() << '\n';
        if (joe.is_recovered())
            break;
    }

    return 0;
}
