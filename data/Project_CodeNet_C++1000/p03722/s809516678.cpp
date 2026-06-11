#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007
 
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool debug=false;
 
/*---------------------------------------------------*/


struct Edge{
    long long to, cost;
    Edge(long t, long c){
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
        Bellman_Ford(int v){
            dist = vector<long long>(v + 1);
            adj = vector<vector<Edge> >(v + 1);
            for(int i = 0; i < (int)dist.size(); i++)dist[i] = Inf;
        }

        void add_edge(int from, int to, int cost){
            adj[from].push_back(Edge(to, cost));
        }

        bool shortest_path(int s){
            dist[s] = 0;
            for(int k = 0; k < (int)dist.size(); k++){
                for(int i = 0; i < (int)dist.size(); i++){
                    for(int  j = 0; j < (int)adj[i].size(); j++){
                        Edge e = adj[i][j];
                        if(dist[e.to] > dist[i] + e.cost && dist[i] != Inf){
                            dist[e.to] = dist[i] + e.cost;
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

int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    Bellman_Ford bel(n + 1);
    rep(i, m){
        cin >> a >> b >> c;
        bel.add_edge(a, b, -c);
    }
    bel.shortest_path(1);
    ll first = bel.get_distance(n);
    bel.shortest_path(1);
    ll second = bel.get_distance(n); 
    if(first == second){
        cout << -first << endl;
    }else{
        cout << "inf" << endl;
    }
    return 0;
}
