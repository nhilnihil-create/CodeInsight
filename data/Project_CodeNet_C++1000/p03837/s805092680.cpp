#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll n,m;vector<vector<ll>>d;
vector<vector<bool>>ch;
vector<vector<ll>>via;
ll ans=0;
void solve(ll s,ll g){
    if(s==g)return;
    if(via[s][g]==s){
        if(ch[s][g]){
//            cout <<s<<" "<<g<<endl;
//            cout <<d[s][g]<<endl;
//            cout <<via[s][g]<<endl;
            ans++;
        }
        ch[s][g]=false;
        return;
    }
//    cout <<"!"<<endl;
    solve(s,via[s][g]);
    solve(via[s][g],g);
}

int main(){
    cin >>n>>m;
    d.assign(n,vector<ll>(n,INF));
    ch.assign(n,vector<bool>(n,false));
    via.assign(n,vector<ll>(n));
    for (int i = 0; i < m; ++i) {
        ll a,b,c;cin >>a>>b>>c;
        a--;b--;
        d[a][b]=c;
        d[b][a]=c;
        ch[a][b]=true;
    }
    for (int i = 0; i < n; ++i) {
        d[i][i]=0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            via[i][j]=i;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(d[i][j]>d[i][k]+d[k][j]){
//                    if(i==1&&j==2){
//                        cout <<k<<" "<<d[i][j]<<" "<<d[i][k]<<" "<<d[k][j]<<endl;
//                    }
                    d[i][j]=d[i][k]+d[k][j];
                    via[i][j]=k;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
//            cout <<i<<" "<<j<<" "<<via[i][j]<<endl;
            solve(i,j);
//            cout <<ans <<endl;
        }
    }
    cout<<m-ans<<endl;
    return 0;
}

