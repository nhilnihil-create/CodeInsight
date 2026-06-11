#include <iostream>

using namespace std;

int N;

void solve() {
    int counter = 0;
    if (!N)
        return;

    while (true) {
        ++counter;
        int kagen = counter * (counter - 1) / 2;
        int jyogen = counter * (counter + 1) / 2;
        if (kagen < N && N <= jyogen) {
            cout << counter << endl;
            N -= counter;
            break;
        }
    }

    solve();
}

int main() {
    cin >> N;

    solve();
}
