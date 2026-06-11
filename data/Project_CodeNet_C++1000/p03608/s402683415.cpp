#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

ll d[210][210];

int main() {
    int N,M,R;
    cin>>N>>M>>R;
    vector<int> r(R);
    rep(i,R){
        cin>>r[i];
        r[i]--;
    }

    rep(i,N){
        rep(j,N){
            if(i==j) continue;
            d[i][j]=INF;
        }
    }
    rep(i,M){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--,b--;
        d[a][b]=c;
        d[b][a]=c;
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    vector<int> ord(R);
    rep(i,R) ord[i]=i;

    ll ans=INF;

    do{ 
        ll tmp=0;
        rep(i,R-1){
            tmp+=d[r[ord[i]]][r[ord[i+1]]];
        }
        //cout<<tmp<<endl;
        ans=min(ans,tmp);
    }while(next_permutation(all(ord)));

    cout<<ans<<endl;
}