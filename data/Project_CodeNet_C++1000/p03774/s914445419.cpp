#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab.at(i).first;
        cin >> ab.at(i).second;
    }
    vector<pair<int,int>> cd(m);
    for (int i = 0; i < m; i++) {
        cin >> cd.at(i).first;
        cin >> cd.at(i).second;
    }

    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; i++) {
        ans.at(i).first = 1;
        ans.at(i).second = 500000000;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = abs(ab.at(i).first - cd.at(j).first) + abs(ab.at(i).second - cd.at(j).second);
            if (tmp < ans.at(i).second) {
                ans.at(i).first = j + 1;
                ans.at(i).second = tmp;
            }
        }
        cout << ans.at(i).first << endl;
    }
}