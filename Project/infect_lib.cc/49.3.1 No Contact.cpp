#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "infect_lib.cc

class Disease;

class Person {
private:
    enum class State { Healthy, Sick, Recovered, Vaccinated };
    State state;
    int daysToRecover;
    int contactsMade;

public:
    Person() : state(State::Healthy), daysToRecover(0), contactsMade(0) {}

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
        contactsMade = 0; // Reset daily contacts
        if (state == State::Sick) {
            daysToRecover--;
            if (daysToRecover == 0) {
                state = State::Recovered;
            }
        }
    }

    void infect(const Person& contactPerson) {
        if (state == State::Healthy && contactPerson.state == State::Sick) {
            state = State::Sick;
            daysToRecover = contactPerson.daysToRecover;
        }
    }

    bool is_recovered() const {
        return state == State::Recovered;
    }

    State get_state() const {
        return state;
    }

    void vaccinate() {
        state = State::Vaccinated;
    }

    void make_contact() {
        contactsMade++;
    }

    int get_contacts_made() const {
        return contactsMade;
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

    bool transmit() const {
        return (rand() % 100) < transmissionChance;
    }
};

class Population {
private:
    std::vector<Person> people;

public:
    Population(int size) {
        people.reserve(size);
    }

    void random_infection(const Disease& disease, int initialInfected);
    void random_vaccination(int percentage);
    int count_infected() const;
    void one_more_day();
};

void Population::random_infection(const Disease& disease, int initialInfected) {
    for (int i = 0; i < initialInfected; ++i) {
        int index = rand() % people.size();
        people[index].infect(people[index]); // Infect a person within the population
    }
}

void Population::random_vaccination(int percentage) {
    int numToVaccinate = (percentage * people.size()) / 100;
    for (int i = 0; i < numToVaccinate; ++i) {
        int index = rand() % people.size();
        people[index].vaccinate();
    }
}

int Population::count_infected() const {
    int count = 0;
    for (const Person& person : people) {
        if (person.get_state() == Person::State::Sick) {
            count++;
        }
    }
    return count;
}

void Population::one_more_day() {
    for (Person& person : people) {
        person.one_more_day();

        // Simulate interactions and transmission
        int numInteractions = 6; // Set the number of daily interactions
        for (int i = 0; i < numInteractions; ++i) {
            int index = rand() % people.size();
            if (people[index].get_state() == Person::State::Sick) {
                person.infect(people[index]);
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    const int populationSize = 1000;
    Population population(populationSize);
    Disease flu(5, 2); // Example disease with 5% transmission chance and 2 days to recover

    // Initial random infection of 1% of the population
    population.random_infection(flu, populationSize / 100);

    // Vaccinate 100% of the population
    population.random_vaccination(100);

    for (int step = 1;; ++step) {
        population.one_more_day();
        std::cout << "On day " << step << ", Infected: " << population.count_infected() << '\n';

        // Add any other logic or conditions as needed

        // Break the loop when no one is infected
        if (population.count_infected() == 0)
            break;
    }

    return 0;
}
