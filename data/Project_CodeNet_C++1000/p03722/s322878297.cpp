#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
int main(){
    int n,m;cin >> n >> m;
    vector<vector<pair<int,ll>>> g(n);
    for(int i=0;i<m;i++){
        int a,b;ll c;
        cin >> a >> b >> c;
        a--,b--;
        g[a].push_back({b,-c});
    }
    vector<ll> d(n,INF);
    bool f=false;
    d[0]=0;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<n;j++){
            if(d[j]>=INF/2){
                continue;
            }
            for(auto x:g[j]){
                if(d[x.first]>d[j]+x.second){
                    d[x.first]=d[j]+x.second;
                    if(x.first==n-1&&i==2*n){
                        f=true;
                    }
                }
            }
        }
    }
    if(!f){
        cout << -d[n-1] << endl;
    }
    else{
        cout << "inf" << endl;
    }
}