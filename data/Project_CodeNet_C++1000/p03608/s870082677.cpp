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
static const long double pi = 3.141592653589793;



int main(){
    ll N, M, R;
    cin>>N>>M>>R;
    vector<ll> r(R);
    rep(i, R){
        cin>>r[i];
        r[i]--;
    }
    vector<ll> A(M), B(M), C(M);
    vector<vector<ll>> Way(N, vector<ll>(N, INF));
    rep(i, M){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--; B[i]--;
        Way[A[i]][B[i]]=min(Way[A[i]][B[i]],C[i]);
        Way[B[i]][A[i]]=min(Way[B[i]][A[i]],C[i]);
    }
  	rep(i, N){
      	Way[i][i]=0;
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                Way[i][j]=min(Way[i][j], Way[i][k]+Way[k][j]);
            }
        }
    }
    sort(ALL(r));
    ll Ans=INF;
    do{
        ll Num=0;
        rep(i, R-1){
            Num+=Way[r[i]][r[i+1]];
        }
        Ans=min(Ans, Num);
    }while(next_permutation(ALL(r)));
  
    if(Ans!=INF){
        cout<<Ans<<endl;
    }else{
        cout<<-1<<endl;
    }
}
     
