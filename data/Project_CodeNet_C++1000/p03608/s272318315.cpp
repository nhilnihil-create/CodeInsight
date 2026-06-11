#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define Pl pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

void
Warshall_Floyd(int V, vector<vector<int>> &G)
{
  rep(i, 0, V){
    rep(k, 0, V){
      rep(l, 0, V){
        chmin(G[k][l], G[k][i] + G[i][l]);
      }
    }
  }
}

int main()
{
  int N, M, R; cin >> N >> M >> R;
  vector<int> des(R);
  rep(i, 0, R){
    int tmp; cin >> tmp;
    --tmp;
    des[i] = tmp;
  }
  sort(des.begin(), des.end());
  vector<vector<int>> G(N, vector<int>(N, iINF));
  rep(i, 0, N) G[i][i] = 0;
  rep(i, 0, M){
    int a, b, c; cin >> a >> b >> c;
    --a, --b;
    G[a][b] = c;
    G[b][a] = c;
  }

  Warshall_Floyd(N, G);

  int ans = iINF;
  do{
    int comp = 0;
    int pre = des[0];
    rep(i, 1, R){
      comp += G[pre][des[i]];
      pre = des[i];
    }
    chmin(ans, comp);
  } while(next_permutation(des.begin(), des.end()));

  cout << ans << endl;
}