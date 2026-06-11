#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>
#include <random>
#include <cstring>

#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back

using namespace std;
using ll = long long;


const ll mod = 1000000007;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
// bool debug=false;

/*---------------------------------------------------*/


struct Edge{
    long long to, cost;
    Edge(long long t, long long c){
        to = t;
        cost = c;
    }
};

class Bellman_Ford{
    private:
        const long long Inf = 1LL << 50;
        vector<long long> dist;
        vector<vector<Edge> > adj;
    public:
  Bellman_Ford(int v, int s){
            dist.resize(v + 1);
            adj.resize(v + 1);
	    for(int i = 0; i < (int)dist.size(); i++) dist[i] = Inf;
	    dist[s] = 0;
        }

        void add_path(int from, int to, long long cost){
            adj[from].push_back(Edge(to, cost));
        }

        bool shortest_path(int s){            
            int cnt = 0;
            bool update = true;
            while(update){
                if(cnt > (int)dist.size() + 1)return false;
                cnt++;
                update = false;
                for(int i = 0; i < (int)dist.size(); i++){
                    for(int  j = 0; j < (int)adj[i].size(); j++){
                        Edge e = adj[i][j];
                        if(dist[e.to] > dist[i] + e.cost && dist[i] != Inf){
                            dist[e.to] = dist[i] + e.cost;
                            update = true;
                        }
                    }
                }
            }
            return true;
        }

        long long get_distance(int x){
            return dist[x];
        }

        void DEBUG(){
            for(int i = 0; i < (int)dist.size(); i++){
                cout << 1 << " --> " << i << " = " << dist[i] << endl;
            }
        }
};

int main() {
  long long N, M, a, b, c;
  cin >> N >> M;
  Bellman_Ford bel = Bellman_Ford(N, 0);
  for(int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    a--; b--;
    bel.add_path(a, b, -c);
  }
  
  bel.shortest_path(0);
  long long first_cost = -bel.get_distance(N - 1);
  bel.shortest_path(0);
  long long second_cost = -bel.get_distance(N - 1);
  if(first_cost == second_cost) {
    cout << -bel.get_distance(N - 1) << endl;
  } else {
    cout << "inf" << endl;
  }
  return 0;
}
