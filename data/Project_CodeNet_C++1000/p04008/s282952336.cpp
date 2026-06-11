#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vvec<int> g(N);
    int ans = 0;
    vec<int> par(N,-1);
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        a--;
        if(!i) ans = a!=0;
        else g[a].push_back(i);
    }

    vec<int> dep(N,-1);
    auto dfs = [&](auto&& self,int cur,int par)->void{
        int ma = 0;
        for(auto& to:g[cur]) if(to!=par){
            self(self,to,cur);
            ma = max(ma,dep[to]+1);
        }
        if(par>0 && ma==K-1){
            ans++;
            dep[cur] = -1;
        }else{
            dep[cur] = ma;
        }
    };
    
    dfs(dfs,0,-1);
    cout << ans << "\n";
}