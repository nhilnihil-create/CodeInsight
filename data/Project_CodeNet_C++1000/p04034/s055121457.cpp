#include <bits/stdc++.h>
using namespace std;
// for(long long i = 0;i < num; i++){}
int main() {
    //
    int num, m;
    int befor, after;
    int cnt = 0;

    cin >> num >> m;

    vector<vector<int>> vec(num, vector<int>(2));
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            vec.at(0).at(0) = 1;
            vec.at(0).at(1) = 1;
            continue;
        }
        vec.at(i).at(0) = 1;
        vec.at(i).at(1) = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> befor >> after;
        befor--;
        after--;

        if (vec.at(befor).at(1) == 1) {
            vec.at(after).at(0)++;
            vec.at(after).at(1) = 1;

            vec.at(befor).at(0)--;
            if (vec.at(befor).at(0) == 0) vec.at(befor).at(1) = 0;
        } else {
            vec.at(after).at(0)++;
            vec.at(befor).at(0)--;
        }
    }

    for (int i = 0; i < num; i++) {
        if (vec.at(i).at(1) == 1) {
            cnt++;
        }
    }

    cout << cnt;
    //
}
