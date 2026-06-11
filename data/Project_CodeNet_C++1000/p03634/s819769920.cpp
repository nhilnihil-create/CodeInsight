#include<bits/stdc++.h>
using namespace std;
int n,k;
map<pair<int,int>,long long int> mp;
vector<int> v[100005];
long long int d[100005];
void solve(int now,int before,long long int dis){
    if(now==before){
        for(auto u:v[now]){
            d[u]=mp[make_pair(min(now,u),max(now,u))];
            solve(u,now,mp[make_pair(min(now,u),max(now,u))]);
        }
    }
    else{
        for(auto u:v[now]){
            if(u!=before){
                if(d[u]>dis+mp[make_pair(min(now,u),max(now,u))]){
                    d[u]=dis+mp[make_pair(min(now,u),max(now,u))];
                    solve(u,now,dis+mp[make_pair(min(now,u),max(now,u))]);
            }}
        }
    }
}

int main(){
    cin >> n;
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        mp[make_pair(min(a,b),max(a,b))]=c;
    }
    int q;
    cin >> q >> k;
    for(int i=1;i<=n;i++)d[i]=1e18;
    solve(k,k,0);
    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        cout << d[x]+d[y] << endl;
    }
}