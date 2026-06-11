#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> abc(3);
    cin >> abc.at(0) >> abc.at(1) >> abc.at(2);
    for (int i = 0; i < 3; i++) {
        if (abc.at(i) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    sort(abc.begin(), abc.end());
    cout << abc.at(0) * abc.at(1) << endl;
    return 0;
}