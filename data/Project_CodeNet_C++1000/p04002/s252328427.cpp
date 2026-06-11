#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    map<pair<ll,ll>, int> num;
    ll a,b;
    ll dx[9]={-1,0,1,-1,0,1,-1,0,1}, dy[9]={-1,-1,-1,0,0,0,1,1,1};
    for ( int i = 0; i < N; i++ ) {
        cin >> a >> b;
        a--, b--;
        for ( int j = 0; j < 9; j++ ) {
            ll aa = a + dx[j], bb = b + dy[j];
            if ( aa >= 0 && aa < H && bb >= 0 && bb < W ) num[make_pair(aa, bb)]++;
        }
    }
    vector<ll> nums(10);
    for ( auto& p : num ) {
        a = p.first.first;
        b = p.first.second;
        if ( a > 0 && a < H-1 && b > 0 && b < W-1 ) nums[p.second]++;
    }
    nums[0] = (H-2) * (W-2);
    for ( int j = 1; j < 10; j++ ) {
        nums[0] -= nums[j];
    }
    
    for ( int j = 0; j < 10; j++ ) {
        cout << nums[j] << "\n";
    }
    return 0;
}