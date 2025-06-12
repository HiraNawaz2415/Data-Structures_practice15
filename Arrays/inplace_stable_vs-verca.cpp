//2415..
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int age;

    // Display function
    void display() const {
        cout << name << " (" << age << ")" << endl;
    }
};

// Comparison function: sort by age
bool compareByAge(const Person &a, const Person &b) {
    return a.age < b.age;
}

int main() {
    vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 25},
        {"Dave", 30},
        {"Eve", 22}
    };

    cout << "Original Order:\n";
    for (const auto &p : people) p.display();

    // Unstable sort (may change order of equal ages)
    vector<Person> unstableSorted = people;
    sort(unstableSorted.begin(), unstableSorted.end(), compareByAge);
    cout << "\nAfter std::sort (Unstable):\n";
    for (const auto &p : unstableSorted) p.display();

    // Stable sort (preserves order of equal ages)
    vector<Person> stableSorted = people;
    stable_sort(stableSorted.begin(), stableSorted.end(), compareByAge);
    cout << "\nAfter std::stable_sort (Stable):\n";
    for (const auto &p : stableSorted) p.display();

    return 0;
}

