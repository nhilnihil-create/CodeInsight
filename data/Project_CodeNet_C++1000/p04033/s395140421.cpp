#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int A, B;
    cin >> A >> B;
    if(A == 0 || B == 0) {
        cout << "Zero";
        return 0;
    }
    if(B < 0) {
        if((B - A) % 2 == 1) {
            cout << "Positive";
            return 0;
        } else {
            cout << "Negative";
            return 0;
        }
    }
    if(A < 0) {
        cout << "Zero";
        return 0;
    }
    cout << "Positive";
    return 0;
}
