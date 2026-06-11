#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> v(111111);
bool used[111111];

ll dfs(int p){
    ll ret = 0;
    used[p] = 1;
    vector<int> e;
    for(auto i:v[p]){
        if(!used[i]){
            ll t = dfs(i);
            e.push_back(t);
        }
    }
    sort(e.begin(),e.end(),greater<int>());
    for(ll i=0;i<e.size();i++){
        ret = max(ret, e[i] + i + 1);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

   int n;
   cin>>n;
   for(int i=2;i<=n;i++){
       int a;
       cin>>a;
       v[a].push_back(i);
       //v[i].push_back(a);
   }
   ll ans = dfs(1);
   //ans--;
   cout<<ans<<endl;
   
}