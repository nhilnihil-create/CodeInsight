#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define erep(i, n) for (int i = 0; i <= (n); i++)
#define erep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int time[101] = {0};
    erep1(i, 100) {
        if (A < i && i <= B) time[i]++;
        if (C < i && i <= D) time[i]++;
    }
    int count = 0;
    erep1(i, 100) {
        if (time[i] == 2) count++;
    }
    cout << count << endl;
}