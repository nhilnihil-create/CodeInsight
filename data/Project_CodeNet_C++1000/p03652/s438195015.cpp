#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;



int main(){
   ll N, M;
   cin>>N>>M;
   vector<vector<ll>> A(N, vector<ll>(M));
   vector<bool> C(M, true);
   rep(i, N){
       rep(j, M){
           cin>>A[i][j];
           A[i][j]--;
       }
   }
    ll Ans=N;
    rep(i, M){
        vector<ll> Num(M, 0);
        rep(j, N){
            rep(k, M){
                if(C[A[j][k]]){
                  Num[A[j][k]]++;
                break;
                }
            }
        }
        ll MaxN=0;
        rep(j, M){
          	//cout<<Num[j]<<" ";
            MaxN=max(MaxN, Num[j]);
        }
        Ans=min(Ans, MaxN);
      	//cout<<Ans;
        rep(j, M){
            if(Num[j]==MaxN){
                C[j]=false;
              	//cout<<" "<<j<<endl;
                break;
            }
        }
    }
    cout<<Ans<<endl;
}

