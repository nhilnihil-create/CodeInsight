#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int mod = 1000000007;

ll kai(ll N){
    ll res = 1;
    for(ll i=1;i<=N;i++){
        res*=i;
    }
    return res;
}

int main(){
    ll N,M,R;
    cin>>N>>M>>R;
    vector<ll> r(R);
    for(ll i=0;i<R;i++){
        cin>>r[i];
        r[i]--;
    }
    ll d[N][N];
    ll INF = 99999999999;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;
        }
    }
    for(ll i=0;i<M;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        d[a][b] = c;
        d[b][a] = c;
    }

    for(ll k = 0;k<N;k++){
        for(ll i=0;i<N;i++){
            for(ll j=0;j<N;j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }


    ll res=INF;
    for(ll i=0;i<kai(R)-1;i++){
        ll tmp=0;
        for(ll j=0;j<R-1;j++){
            tmp+=d[r[j]][r[j+1]];
        }
        res=min(tmp,res);
        next_permutation(r.begin(),r.end());
    }
    cout<<res<<endl;
}