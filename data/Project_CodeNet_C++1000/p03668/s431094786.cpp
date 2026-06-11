#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<int>> v(100010);
bool used[100010];

int dfs(int p){
    used[p] = true;
    int x = 0;
    for(auto i:v[p]){
        if(!used[i]){
            x ^= dfs(i) + 1;
        }
    }
    return x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll ans = dfs(0);
    if(ans){
        cout << "Alice" << endl;
    }
    else cout << "Bob" << endl;
}