#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

int main(void) {
    int64_t H, W, N;
    cin >> H >> W >> N;
    map<pair<int,int>, int> mp;
    while(N--) {
        int a, b;
        cin >> a >> b;
        mp[make_pair(a-1, b-1)]++;
        mp[make_pair(a-1, b)]++;
        mp[make_pair(a-1, b+1)]++;
        mp[make_pair(a, b-1)]++;
        mp[make_pair(a, b)]++;
        mp[make_pair(a, b+1)]++;
        mp[make_pair(a+1, b-1)]++;
        mp[make_pair(a+1, b)]++;
        mp[make_pair(a+1, b+1)]++;
    }

    vector<int64_t> ans(10);
    for(auto e: mp) {
        if(e.first.first < 2 || e.first.first > H-1 || e.first.second < 2 || e.first.second > W-1) continue;
        ans[e.second]++;
    }
    ans[0] = (H-2)*(W-2) - accumulate(ans.begin(), ans.end(), 0L);

    for(auto e: ans) {
        cout << e << endl;
    }
    return 0;
}
