#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

// order statistics tree
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update> indexed_set;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const int N = 301;
const ll INF = 1e18;

int n;
ll graph[N][N];
int used[N][N];

ll dist[N][N]; // shortest distance between verts i, j
ll ans;
int main() {
  cin.tie(0); cin.exceptions(cin.failbit);

  bool possible = true;
  scanf("%d", &n);

  rep(i, 0, n){
    rep(j, 0, n){
      scanf("%lld", &graph[i][j]);
    }
  }

  // dijkstra's for each vertex
  rep(source, 0, n){
    priority_queue<pll, vector<pll>, greater<pll>> q;

    ll len[N], // keep track of current minimum length from source other vertices
      prev[N]; // keep track of previous vertex in path back to source

    rep(v, 0, n){
      len[v] = INF;
      prev[v] = -1;
    }
    len[source] = 0;

    // get the ball rolling
    // push the source vertex into queue
    q.push({0, source}); // distance, vertex

    while(!q.empty()){
      auto p = q.top();
      q.pop();

      ll l = p.F; // length
      ll v = p.S; // vertex #

      // ignore outdated objects pushed into queue
      // a vertex can acquire a better length before we reach it in q
      if(l > len[v]) continue;

      // iterate through all neighbors of v
      rep(neighbor, 0, n){

        // I am not my own neighbor
        if(neighbor == v) continue;

        // distance to v + distance from v to neighbor
        ll new_dist = l + graph[v][neighbor];

        if(new_dist < len[neighbor]){
          len[neighbor] = new_dist;
          prev[neighbor] = v;
          q.push({new_dist, neighbor});
        } else if(new_dist == len[neighbor] &&
                  graph[v][neighbor] < graph[prev[neighbor]][neighbor]){
          // try to get only the smallest neighbors
          // is this correct?
          prev[neighbor] = v;
        }
      }
    }

    rep(i, 0, n){
      // printf("%lld ", len[i]);
      if(len[i] != graph[source][i]){
        possible = false;
        break;
      }

      if(prev[i] != -1){
        used[i][prev[i]]++;
        used[prev[i]][i]++;
      }

      // printf("%d ", prev[i]);
    }
    // puts("");

    if(!possible) break;
  }


  if(possible){
    // rep(i, 0, n){
    //   rep(j, 0, n){
    //     printf("%lld ", used[i][j]);
    //   }
    //   puts("");
    // }

    rep(i, 0, n){
      rep(j, i+1, n){
        if(used[i][j]){
          ans += graph[i][j];
        }
      }
    }
    cout << ans << endl;
  } else{
    puts("-1");
  }
}
