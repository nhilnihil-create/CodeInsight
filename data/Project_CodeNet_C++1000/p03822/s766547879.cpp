#include <bits/stdc++.h>
using namespace std;


vector<int> g[100010];

int dfs(int root){
    vector<int> r;
    for( auto i : g[root]){
        r.push_back(dfs(i));
    }
    sort(r.rbegin(), r.rend());
    int mx = 0;
    for(int i = 0 ; i < r.size() ; i++){
        mx = max(mx, r[i] + i + 1);
    }
    return mx;
}

void solve(long long N, vector<long long> a){
    for(int i = 0 ; i < N-1 ; i++){
        g[a[i]-1].push_back(i+1);
    }
    cout << dfs(0) << endl;

}

int main(){    
    long long N;
    scanf("%lld",&N);
    vector<long long> a(N-2+1);
    for(int i = 0 ; i < N-2+1 ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, a);
    return 0;
}

