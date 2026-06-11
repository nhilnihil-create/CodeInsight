#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 1e5 + 5;

ll dpM[N], dpm[N], a[N];

vector<int> g[N];
bool ans = true;

void gdp(int u, int p = -1){
	if(g[u].size() == 1){
		dpM[u] = dpm[u] = a[u];
		return;
	}
	ll maxw = -1, sumM = 0, summ = 0;
	for(int v: g[u]){
		if(v == p)continue;
	 	gdp(v, u);
		gmax(maxw, dpM[v]);
		sumM += dpM[v];
		summ += dpm[v];
	}
	if(sumM < a[u])ans = false;
	ll w = a[u];
	dpM[u] = min(w,2 * w - summ);
	dpm[u] = max(max(w-(2*maxw > sumM?sumM-maxw:sumM/2),2*w-sumM),0LL);
	if(dpm[u] > sumM || dpm[u] > dpM[u])ans = false;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	rep(i,0,n)cin >> a[i];
	if(n == 2){
		cout << (a[0] == a[1]?"YES":"NO") << '\n';
		return 0;
	}
	rep(i,0,n-1){
		int x,y;
		cin >> x >> y;
		--x,--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	rep(i,0,n){
		if(g[i].size() != 1){
			gdp(i);
			ans &= dpm[i] == 0;
			break;
		}
	}
	cout << (ans?"YES":"NO") << '\n';
}
