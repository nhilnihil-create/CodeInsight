#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b,c) for(int i=a;i<b;i+=c)
#define REPN(i,a,b,c) for(int i=a;i<=b;i+=c)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

vi adjList[100010];
int col[100010];

int main(void){
	int n,m;
	sc(n);sc(m);
	FOR(i,m){
		int fr, to;
		sc(fr);sc(to);
		adjList[fr].pb(to);
		adjList[to].pb(fr);
	}

	int solo = 0;
	int bip, nobip;
	bip = nobip = 0;
	reset(col, -1);

	for(int i = 1;i<=n;i++){
		if(col[i] != -1)continue;
		if(adjList[i].empty()){
			solo++;
			continue;
		}

		queue<int> q;
		q.push(i);
		col[i] = 0;
		bool valid = true;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int nxt : adjList[node]){
				if(col[nxt] == -1){
					q.push(nxt);
					col[nxt] = 1 ^ col[node];
				}else{
					if(col[nxt] == col[node])valid = false;
				}
			}
		}
		if(valid)bip++;
		else nobip++;
	}
	// cout << bip << " " << nobip << endl;
	ll tot = 0;
	tot += 2LL * n * solo - (1LL * solo * solo);
	tot += 2LL * bip * bip;
	tot += 2LL * bip * nobip;
	tot += 1LL * nobip * nobip;

	cout << tot << "\n";

    return 0;
}
