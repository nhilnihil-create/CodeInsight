#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> v = {0}, index = {0};
    map<int,vector<int>> mp;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        if(a > v.back()) {
            v.emplace_back(a);
            index.emplace_back(i);
        }
        mp[*lower_bound(v.begin(), v.end(), a)].emplace_back(a);
    }

    int64_t cnt = 0;
    vector<int64_t> ans(N);
    reverse(v.begin(), v.end());
    reverse(index.begin(), index.end());
    for(int i=0; i+1<v.size(); i++) {
        ans[index[i]] += cnt * (v[i] - v[i+1]);
        for(auto e: mp[v[i]]) {
            ans[index[i]] += e - v[i+1];
            ++cnt;
        }
    }

    for(auto e: ans) {
        cout << e << endl;
    }
    return 0;
}
