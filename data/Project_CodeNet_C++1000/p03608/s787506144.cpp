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

ll N, M, R;
vector<ll> r(9);
vector<vector<ll>> Way(202, vector<ll>(202, INF));
vector<ll> A(20000), B(20000), C(20000);
vector<bool> used(9);
ll res=INF;
void dfs(int c,int las,int dist) {
    if(c==R) {
		if(res>dist)res=dist; 
      	return;
	}
	for(int i=0;i<R;i++){
      if(!used[i]) {
              used[i]=true;
      	if(las==-1){
              dfs(c+1,i,0);
      	}else{
        		dfs(c+1,i,dist+Way[r[las]][r[i]]);
      	}
      	used[i]=false;
      	}
     }
  }
 

int main(){
    cin>>N>>M>>R;
    rep(i, R){
        cin>>r[i];
        r[i]--;
    }
    vector<ll> A(M), B(M), C(M);
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
  	/*rep(i, N){
		rep(j, N){
          cout<<Way[i][j]<<" ";
        }
      	cout<<endl;
    }*/
   dfs(0,-1,0);
  	cout<<res<<endl;
}
     