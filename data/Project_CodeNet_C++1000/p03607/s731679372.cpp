#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> numbers;
    int target_number;
    for (int i = 0; i < n; ++i) {
        cin >> target_number;
        if (numbers.find(target_number) != numbers.end()) {
            numbers.erase(target_number);
            continue;
        }
        numbers.insert(target_number);
    }

    cout << numbers.size() << endl;

    return 0;
}