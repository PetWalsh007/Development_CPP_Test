#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Function prototype
void newFunction();

int main() {

    vector<int> numbers = {5, 80, 8, 6, 2};
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted numbers: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Call a function
    newFunction();

    return 0;
}

void newFunction() {
    cout << "This is a new function" << endl;
}



