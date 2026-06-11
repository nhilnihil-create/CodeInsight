#include <bits/stdc++.h>

using namespace std;

int main() {
    array<int, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    set<array<int, 3>> used;
    while (a[0] % 2 == 0 && a[1] % 2 == 0 && a[2] % 2 == 0) {
        used.insert(a);
        long long sum = a[0] + (long long)a[1] + a[2];
        a[0] = (sum - a[0]) / 2;
        a[1] = (sum - a[1]) / 2;
        a[2] = (sum - a[2]) / 2;
        if (used.count(a)) 
            break;
    }
    if (used.count(a)) 
        cout << -1 << "\n";
    else 
        cout << int(used.size()) << "\n";
    return 0;
}