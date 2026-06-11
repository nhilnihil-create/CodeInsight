#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int i = 1, count = 0;
    bool ispossible = false;
    while (true) {
        //cout << "i = " << i << ", a[i-1] = " << a[i-1] << endl;
        if (a[i-1] == 0) {
            break;
        } else if (i == 2) {
            ispossible = true;
            break;
        }
        int prev_i = i;
        i = a[i-1];
        a[prev_i-1] = 0;
        count++;
    }

    if (ispossible) {
        cout << count << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}