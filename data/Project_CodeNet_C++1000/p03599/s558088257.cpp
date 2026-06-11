#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
#define INF (1ll<<40-1)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define pi 3.14159265358979323846

int main(){
    ll A,B,C,D,E,F;cin>>A>>B>>C>>D>>E>>F;

    ll dp[3010/*全質量*/];//全質量に対する割合が最も大きくなるような塩分量
    rep(i,3010) dp[i]=-1;
    dp[0]=0;

    rep(i,F+1){
        if(dp[i]==-1) continue;

        if(i+C<=3000 && (100+E)*(C+dp[i])<=E*(i+C)){//Cを加えても濃度E以下の時
            chmax(dp[i+C],dp[i]+C);
        }else{//濃度が超過する場合
            if(i+C+100*A<=3000 && (100+E)*(C+dp[i])<=E*(i+C+100*A)){//さらに100Aの水を加えるとき
                chmax(dp[i+C+100*A],dp[i]+C);
            }
            if(i+C+100*B<=3000 && (100+E)*(C+dp[i])<=E*(i+C+100*B)){//さらに100Bの水を加えるとき
                chmax(dp[i+C+100*B],dp[i]+C);
            }
        }

        if(i+D<=3000 && (100+E)*(D+dp[i])<=E*(i+D)){//Dを加えても濃度E以下の時
            chmax(dp[i+D],dp[i]+D);
        }else{//濃度が超過する場合
            if(i+D+100*A<=3000 && (100+E)*(D+dp[i])<=E*(i+D+100*A)){//さらに100Aの水を加えるとき
                chmax(dp[i+D+100*A],dp[i]+D);
            }
            if(i+D+100*B<=3000 && (100+E)*(D+dp[i])<=E*(i+D+100*B)){//さらに100Bの水を加えるとき
                chmax(dp[i+D+100*B],dp[i]+D);
            }
        }
    }

    ll water,salt;
    ll answater=min(100*A,100*B),anssalt=0;
    for(ll i=1;i<=F;i++){
        if(dp[i]==-1) continue;
        water=i;
        salt=dp[i];
        if(anssalt*water<salt*answater){
            answater=water;
            anssalt=salt;
        }
    }
    
    cout<<answater<<" "<<anssalt<<endl;

    return 0;
}