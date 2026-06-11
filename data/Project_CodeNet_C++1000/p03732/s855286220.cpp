#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<vector<int>> v(4, vector<int>());
    int w1, v1;
    cin >> w1 >> v1;
    v.at(0).push_back(v1);
    for (int i = 0; i < n - 1; i++) {
        int wi, vi;
        cin >> wi >> vi;
        v.at(wi - w1).push_back(vi);
    }
    
    for (int i = 0; i < 4; i++) {
        sort(v.at(i).begin(), v.at(i).end());
        reverse(v.at(i).begin(), v.at(i).end());
    }

    vector<vector<long long>> sum(4, vector<long long>(110, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < (int)v.at(i).size(); j++) {
            sum.at(i).at(j + 1) = sum.at(i).at(j) + v.at(i).at(j);
        }
    }

    long long ans = 0;
    for (int i = 0; i <= (int)v.at(0).size(); i++) {
        if (w1 * i > w) break;
        for (int j = 0; j <= (int)v.at(1).size(); j++) {
            if (w1 * i + (w1 + 1) * j > w) break;
            for (int k = 0; k <= (int)v.at(2).size(); k++) {
                if (w1 * i + (w1 + 1) * j + (w1 + 2) * k > w) break;
                for (int l = 0; l <= (int)v.at(3).size(); l++) {
                    if (w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l > w) break;

                    ans = max(ans, sum.at(0).at(i) + sum.at(1).at(j) + sum.at(2).at(k) + sum.at(3).at(l));
                }
            }
        }
    }

    cout << ans << endl;
}   