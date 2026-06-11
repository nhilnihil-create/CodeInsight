#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> occ;
    for (int i = 0, entry; i < 3 && cin >> entry; i++)
        occ[entry]++;
    if (occ.size() == 2 && (occ[7] == 1 && occ[5] == 2)) {
        cout << "YES";
    } else
        cout << "NO";
    return 0;
}
