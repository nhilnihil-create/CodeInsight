#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, prev, ind = -1;
    cin >> n >> k;

    cin >> prev;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x + prev >= k)
            ind = i;
        prev = x;
    }

    if (ind == -1)
        cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for (int i = 1; i < ind; i++)
            cout << i << '\n';
        for (int i = n - 1; i > ind; i--)
            cout << i << '\n';
        cout << ind << '\n';
    }
}