#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> d(10);

bool check(int n) {
    while (n != 0) {
        if (d[n % 10]) return false;
        n /= 10;
    }

    return true;
}

int main() {
    cin >> n >> k;

    int temp;
    for (int i = 0 ; i < k ; ++i) {
        cin >> temp;
        d[temp] = 1;
    }

    for (int i = n ; i <= 999999 ; ++i) {
        if (check(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}
