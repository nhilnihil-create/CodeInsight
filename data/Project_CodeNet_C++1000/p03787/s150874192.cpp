#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define sz(x) (int)(x.size())
#define fi(a, b) for(int i=a;i<b;++i)
#define pb push_back
typedef long long ll;
//////////////////////////

int const N = 2e5 + 41;
int was[N], col[N];
ll ans = 0;
vector<int> e[N];
int n, m;

int dfs(int u){
	was[u] = 1;
	int ret = 2;
	fi(0, sz(e[u])){
		int to = e[u][i];
		if(!was[to]){
			col[to] = col[u] ^ 1;
			ret = min(ret, dfs(to));
		}else{
			if(col[to] != (col[u] ^ 1)){
				ret = 1;
			}
		}
	}
	return ret;
}

void solve(){
	scanf("%d %d",&n,&m);
	fi(0, m){
		int a, b;
		scanf("%d %d",&a,&b);
		--a;--b;
		e[a].pb(b);
		e[b].pb(a);
	}
	ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
	fi(0, n){
		if(was[i]) continue;
		if(sz(e[i]) == 0) ++cnt0;
		else{
			int cur = dfs(i);

			if(cur == 1) ans += (cnt1 + cnt2) * 2;
			else ans += (cnt1 * 2 + cnt2 * 4); 
			

			ans += cur;
			if(cur == 1) ++cnt1;
			else ++cnt2;
		}
	}

	ans += (n + n - cnt0 + 1) * cnt0;
	ans -= cnt0;
	printf("%lld\n",ans);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();


	return 0;
}