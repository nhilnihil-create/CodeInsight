#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;(i)--)
#define rrep1(i,n) for(int i=((int)(n));i>0;(i)--)
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PP;
const int MAX=1e5+10;
const int INF=1e9+10;


int N, M, Q;
vi G[MAX];
int dp[MAX][11];
int col[MAX];

void input(){
    cin>>N>>M;
    rep(i, M){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    rep(v, N){
        rep(d, 11){
            dp[v][d]=INF;
        }
    }
    cin>>Q;
    rep(q, Q){
        int v, d, c;
        cin>>v>>d>>c;
        v--;
        col[Q-1-q] = c;
        dp[v][d] = Q-1-q;

    }
}

void solve(){
    rrep1(d, 10){
        rep(v, N){
            dp[v][d-1] = min(dp[v][d-1], dp[v][d]);
            rep(i, sz(G[v])){
              	int u = G[v][i];
                dp[u][d-1]= min(dp[u][d-1], dp[v][d]);
            }
        }
    }
    rep(v, N){
        int id = dp[v][0];
        if(id == INF){
            cout<<0<<endl;
        }
        else{
            cout<<col[id]<<endl;
        }
    }
}

void output(){
  rep(d, 3){
    rep(v, N){
      cout<<dp[v][d]<<" ";
    }
    cout<<endl;
  }
  
}

int main(){
  input();
  solve();
  //output();
}