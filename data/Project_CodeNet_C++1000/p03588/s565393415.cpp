#include <bits/stdc++.h>

using namespace std;

signed main(){
    int n; cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i){
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    cout << ab[n - 1].first + ab[n - 1].second << endl;
    return 0;
}