#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;



int main(){
    ll n,m;
    cin >> n >> m;
    vector<bool> flag(n,false);
    vector<ll> memo(n,1);
    flag[0]=true;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        if(flag[x]&&memo[x]>1){
            flag[y]=true;
            memo[x]--;
            memo[y]++;
        }
        else if(flag[x]&&memo[x]==1){
            flag[y]=true;
            flag[x]=false;
            memo[x]--;
            memo[y]++;
        }
        else if(!flag[x]){
            memo[x]--;
            memo[y]++;
        }
    }
    ll res=0;
    for(ll i=0;i<n;i++){
        if(flag[i]) res++;
    }
    cout << res << endl;
    return 0;
}  
