#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

void solve(long long W, long long H, std::vector<long long> p, std::vector<long long> q){
    vector<pair<int,int>> v;

    for(int i = 0; i < W; ++i) {
        v.push_back(make_pair(p[i], 0LL));
    }
    for(int j = 0; j < H; ++j) {
        v.push_back(make_pair(q[j], 1LL));
    }
    sort(ALL(v));
    int res = 0;
    int a = W + 1, b = H + 1;
    for(int i = 0; i < v.size(); ++i) {
        if (v[i].second == 0) {
            res += v[i].first * b;
            a--;
        } else {
            res += v[i].first * a;
            b--;
        }
    }
    cout << res << endl;
}

signed main(){
    long long W;
    scanf("%lld",&W);
    long long H;
    scanf("%lld",&H);
    std::vector<long long> p(W-1-0+1);
    for(int i = 0 ; i < W-1-0+1 ; i++){
        scanf("%lld",&p[i]);
    }
    std::vector<long long> q(H-1-0+1);
    for(int i = 0 ; i < H-1-0+1 ; i++){
        scanf("%lld",&q[i]);
    }
    solve(W, H, std::move(p), std::move(q));
    return 0;
}