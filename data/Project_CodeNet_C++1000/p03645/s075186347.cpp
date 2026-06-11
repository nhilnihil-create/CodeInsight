#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m;
    //vector<vector<int>> way(n+10, vector<int>(m+10, 0));
    vector<int> way[n+10];

    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        way[s].push_back(t);
        way[t].push_back(s);
    }

    for (int i = 0; i < way[1].size(); i++) {
        int rp = way[1][i];
        for (int j = 0; j < way[rp].size(); j++) {
            if (way[rp][j] == n) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

}