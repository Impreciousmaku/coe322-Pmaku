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
    int variant; // New member to represent the variant of the disease

public:
    Person() : state(State::Healthy), daysToRecover(0), contactsMade(0), variant(0) {}

    std::string status_string() const {
        switch (state) {
        case State::Healthy:
            return "healthy";
        case State::Sick:
            return "sick (" + std::to_string(daysToRecover) + " days to go), variant " + std::to_string(variant);
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

    void infect(const Disease& disease);

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
    static int globalVariantsCounter;
    static int globalTransmissionsCounter;
    int variant;

public:
    Disease(int transChance, int recoverDays)
        : transmissionChance(transChance), daysToRecover(recoverDays), variant(globalVariantsCounter) {}

    int get_transmission_chance() const {
        return transmissionChance;
    }

    int get_days_to_recover() const {
        return daysToRecover;
    }

    bool transmit() const {
        ++globalTransmissionsCounter;
        return (rand() % 100) < transmissionChance;
    }

    int get_variant() const {
        return variant;
    }

    static int get_global_variants_counter() {
        return globalVariantsCounter;
    }

    static int get_global_transmissions_counter() {
        return globalTransmissionsCounter;
    }
};

int Disease::globalVariantsCounter = 0;
int Disease::globalTransmissionsCounter = 0;

void Person::infect(const Disease& disease) {
    if (state == State::Healthy && disease.transmit()) {
        state = State::Sick;
        daysToRecover = disease.get_days_to_recover();

        if (++Disease::globalTransmissionsCounter % 5 == 0) {
            // Simulate mutation after every 5 transmissions
            Disease::globalVariantsCounter++;
            variant = Disease::globalVariantsCounter;
        }
    }
}

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
        people[index].infect(disease); // Infect a person within the population
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
                person.infect(Disease(5, 2)); // Example disease with 5% transmission chance and 2 days to recover
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    const int populationSize = 1000;
    Population population(populationSize);
    Disease flu(5, 2); // Example disease with 5% transmission chance and 2 days to recover

    population.random_infection(flu, 1); // Infect one random person
    population.random_vaccination(20);    // Vaccinate 20% of the population

    int step;
    for (step = 1; population.count_infected() > 0; ++step) {
        population.one_more_day();
        // ... Perform interactions and infection logic here
    }

    std::cout << "Disease ran its course by step " << step - 1 << std::endl;

    std::cout << "Total global transmissions: " << Disease::get_global_transmissions_counter() << '\n';
    std::cout << "Total global variants: " << Disease::get_global_variants_counter() << '\n';

    return 0;
}
