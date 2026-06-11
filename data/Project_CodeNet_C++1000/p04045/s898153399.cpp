#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> v, int n) {
    while (n > 0) {
        int a = n % 10;
        for (int i : v) if (a == i) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) cin >> v[i];

    while(1) {
        if (check(v, n)) break;
        n++;
    }

    cout << n;
}
