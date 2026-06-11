#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    for (int i = 0; i <= 7; ++i) {
        if (pow(2, i) > N) {
            cout << pow(2, i - 1) << endl; break;
        }
    }
}
