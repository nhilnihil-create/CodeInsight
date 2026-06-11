#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int now, count;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    now = 0;
    count = 0;

    for (int i = 0; i < N; i++) {
        now = vec.at(now) - 1;
        count++;
        if (now == 1) {
            cout << count << endl;
            break;
        }
        if (i == N - 1) {
            cout << -1 << endl;
        }
    }
}