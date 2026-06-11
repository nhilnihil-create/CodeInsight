#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long l = 1;
    for (int i = 0; i < N; i++) {
        long long T;
        cin >> T;
        l = lcm(l, T);
    }
    cout << l << endl;
}