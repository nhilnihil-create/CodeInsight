// All Heil Fire Lord Zuko

#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 19;

int n, a[N];
bool b[N];

bool isValid(int);

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < 2 * n; i ++)
        cin >> a[i];
    int down = 1, up = 2 * n;
    while (up - down > 1) {
        int md = (up + down) / 2;
        if (isValid(md))
            down = md;
        else
            up = md;
    }
    cout << down;
    return 0;
}

bool isValid(int x) {
    for (int i = 0; i < 2 * n; i ++)
        b[i] = a[i] >= x;
    for (int i = 1; i < n; i ++) {
        if (b[n - i] == b[n - i + 1])
            return b[n - i];
        if (b[n + i] == b[n + i - 1])
            return b[n + i];
    }
    if (n % 2)
        return b[n];
    else
        return !b[n];
}

/* THINGS TO CHECK !! */

// Runtime ->
// Overflows ->
// Order is ->

/* READ PROBLEM STATEMENT CAREFULLY */

