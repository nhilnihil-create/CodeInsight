#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
#define int long long
#define endl "\n"
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};

#define cost first
#define to second
#define INF LLONG_MAX

const int MAX_V = 100010;

vector<P> G[MAX_V];
int dist[MAX_V];
int V; // 頂点数

void dijikstra(int s) {
	priority_queue< P, vector<P>, greater<P> > que;
	fill(dist, dist + V, INF);
	dist[s] = 0;
	que.push(P(0, s));

	while(!que.empty()) {
		P p = que.top(); que.pop();
		int next = p.to;
		if(dist[next] < p.cost) continue;
		for(P e : G[next]) {
			if(dist[e.to] > dist[next] + e.cost) {
				dist[e.to] = dist[next] + e.cost;
				que.push(P(dist[e.to], e.to));
			}
		}
	}
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> V;
    rep(i, V-1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(P(c, b));
        G[b].push_back(P(c, a));
    }
    int q, k;
    cin >> q >> k;
    dijikstra(--k);
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dist[x] + dist[y] << endl;
    }
    return 0;
}