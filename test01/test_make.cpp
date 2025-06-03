#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to read numbers from a CSV file
vector<int> read_csv(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            try {
                numbers.push_back(stoi(cell));
            } catch (...) {}
        }
    }
    return numbers;
}

void print_numbers(const vector<int>& numbers) {
    for (int n : numbers) cout << n << " ";
    cout << endl;
}

void print_stats(const vector<int>& numbers) {
    if (numbers.empty()) {
        cout << "No numbers loaded.\n";
        return;
    }
    int min_val = *min_element(numbers.begin(), numbers.end());
    int max_val = *max_element(numbers.begin(), numbers.end());
    double avg = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    cout << "Count: " << numbers.size() << ", Min: " << min_val
         << ", Max: " << max_val << ", Avg: " << avg << endl;
}

int main() {
    auto start = high_resolution_clock::now();

    vector<int> numbers = read_csv("read.csv");
    cout << "Loaded numbers: ";
    //print_numbers(numbers);
    print_stats(numbers);

    // Sort numbers
    sort(numbers.begin(), numbers.end());
    cout << "Sorted numbers: ";
    //print_numbers(numbers);

    // Add a number
    int to_add = 42;
    numbers.push_back(to_add);
    cout << "After adding " << to_add << ": ";
    //print_numbers(numbers);

    // Remove a number
    int to_remove = 10;
    numbers.erase(remove(numbers.begin(), numbers.end(), to_remove), numbers.end());
    cout << "After removing " << to_remove << ": ";
    //print_numbers(numbers);

    // Search for a number
    int to_search = 5;
    auto it = find(numbers.begin(), numbers.end(), to_search);
    if (it != numbers.end())
        cout << to_search << " found at position " << distance(numbers.begin(), it) << endl;
    else
        cout << to_search << " not found." << endl;

    print_stats(numbers);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}
