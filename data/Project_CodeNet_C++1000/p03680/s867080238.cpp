#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;

    int v[100001] = {};
    bool a[100001] = {};

    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        v[i] = xi;
    }

    int now = 0;
    int acc = 0;

    while (!a[now]) {
        a[now] = true;
        if (v[now] == 2) {
            a[1]=true;
            break;
        }
        now = v[now] - 1;
        acc += 1;
    }

    if (a[1]) {
        cout << acc + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}