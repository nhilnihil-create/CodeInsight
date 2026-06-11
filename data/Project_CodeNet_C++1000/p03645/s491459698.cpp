#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int>from_1_to_X;
    map<int, int>d;
    for (int i=0; i<M; i++) {
        int n, m;
        cin >> n >> m;
        if (n == 1) {
            from_1_to_X.emplace_back(m);
        } else if (m == N) {
            d[n] = 1;
        }
    }

    bool is_possible = false;
    for (int i=0; i<from_1_to_X.size(); i++) {
        int chukanti = from_1_to_X[i];
        if (d.count(chukanti) > 0) {
            is_possible = true;
            break;
        }
    }

    if (is_possible) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}