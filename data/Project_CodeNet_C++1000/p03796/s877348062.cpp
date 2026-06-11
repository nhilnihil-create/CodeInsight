#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long waru = 1000000007;
    long long power = 1;

    cin >> num;

    for (int i = 1; i <= num; i++) power = (power * i) % waru;

    cout << power;

    //
}