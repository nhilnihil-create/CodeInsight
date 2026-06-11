#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector <int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);

    int x = 1;
    int count = 0;

    while (x != 0 && x != 2) {
        int y = x;
        x = a.at(x - 1);
        a.at (y - 1) = 0;
        if (x == 0) count = -1;
        else count++;
    }

    cout << count << endl;
}