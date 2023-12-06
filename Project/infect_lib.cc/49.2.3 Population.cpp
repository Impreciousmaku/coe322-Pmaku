#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "infect_lib.cc

// Include the Population class definition and forward declarations
class Person;
class Disease;

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

// Person class definition
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

    void infect(const Person& contactPerson);
    bool is_recovered() const {
        return state == State::Recovered;
    }

    State get_state() const {
        return state;
    }

    void vaccinate() {
        state = State::Vaccinated;
    }
};

// Disease class definition
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

void Person::infect(const Person& contactPerson) {
    if (state == State::Healthy && contactPerson.state == State::Sick) {
        state = State::Sick;
        daysToRecover = contactPerson.daysToRecover;
    }
}

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
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    const int populationSize = 1000;
    Population population(populationSize);
    Disease flu(5, 2); // Example disease with 5% transmission chance and 2 days to recover

    // Initial random infection of 1% of the population
    population.random_infection(flu, populationSize / 100);

    // Initial random vaccination of 20% of the population
    population.random_vaccination(20);

    for (int step = 1;; ++step) {
        population.one_more_day();
        population.random_infection(flu, 1); // Simulate random contacts causing infection
        std::cout << "On day " << step << ", Infected: " << population.count_infected() << '\n';

        // Break the loop when no one is infected
        if (population.count_infected() == 0)
            break;
    }

    return 0;
}
