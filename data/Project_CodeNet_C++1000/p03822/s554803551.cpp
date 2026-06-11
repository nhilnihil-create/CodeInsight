#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
#define sign(a) ((a>0)-(a<0))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define LL long long
#define INF (LL)(1LL<<60)
#define all(a) a.begin(), a.end()
#define gr greater<LL>()

using namespace std;

void solve(long long N, std::vector<long long> a){
    vector<vector<LL>> edges(N);

    rep(i,N-1){
        LL looser=i+1;
        LL winner = a[i]-1;
        edges[winner].emplace_back(looser);
    }

    function<LL(LL)> dfs = [&dfs, &edges](LL curr){
        if(edges[curr].empty())return 0LL;
        LL n = edges[curr].size();
        vector<LL> hs(n);
        rep(i,n)hs[i]=dfs(edges[curr][i])+1;
        sort(all(hs),gr);
        LL max_= 0;
        rep(i,n){
            max_ = max(max_, hs[i]+i);
        }
        return max_;
    };

    cout<< dfs(0) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-2+1);
    for(int i = 0 ; i < N-2+1 ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
