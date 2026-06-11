#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;
    int x = 0, sum = 0;
    do {
        x++;
        sum += x;
    } while (sum < N);

    for (int i = 1; i <= x; i++) {
        if (i == sum - N) continue;
        cout << i << endl;
    }

    return 0;
}