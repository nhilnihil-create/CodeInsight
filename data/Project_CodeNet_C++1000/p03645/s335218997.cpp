#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int bin;
    cin >> num >> bin;

    map<int, int> m;

    for (int i = 0; i < bin; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        if (tmp1 == 1) {
            m[tmp2]++;
        } else if (tmp2 == num) {
            m[tmp1]++;
        }
    }

    for (auto itr : m) {
        if (itr.second >= 2) {
            cout << "POSSIBLE";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}