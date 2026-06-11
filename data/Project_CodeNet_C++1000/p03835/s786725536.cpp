#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;


int main() {
    int K, S;
    cin >> K >> S;

    int num = 0;
    for (int x = 0; x <= K && x <= S; x++) {
        for (int y = 0; y <= K && x + y <= S; y++) {
            if (S - x - y <= K) num++;
        }
    }

    cout << num << endl;
}