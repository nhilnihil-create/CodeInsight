#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vvec<int> g(N);
    for(int i=1;i<N;i++){
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
    }
    int inf = 1e9;
    vec<int> dp(N,0);

    auto dfs = [&](auto&& self,int cur,int par)->void{
        vec<int> c;
        for(auto& to:g[cur]) if(to!=par){
            self(self,to,cur);
            c.push_back(dp[to]);
        }
        if(c.empty()){
            dp[cur] = 0;
            return ;
        }
        sort(c.rbegin(),c.rend());
        int n = c.size();
        for(int i=0;i<n;i++) dp[cur] = max(dp[cur],c[i]+i+1);
    };

    dfs(dfs,0,-1);
//    for(int i=0;i<N;i++) cerr << i << " " << dp[i] << "\n";
    cout << dp[0] << "\n";
}