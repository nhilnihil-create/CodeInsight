#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
const int inf = 1e9+7;
const int INF = 1e18+7;
//26

vector<int> pos[30], vec, ans;
int a[400000], n;
int f[30], cnt = 0;
signed main(){
	string str;
	cin >> str;
	n = str.size();
	vec.pb(n);
	rep(i,30)pos[i].pb(inf);
	rep(i,n)a[i] = str[i]-'a';
	drep(i,n-1,0){
		if(f[a[i]] == 0)cnt++;
		f[a[i]] = 1;
		if(cnt == 26){
			fill(f, f+30, 0);
			cnt = 0;
			vec.pb(i);
		}
		pos[a[i]].pb(i);
	}
	rep(i,30)sort(all(pos[i]));
	sort(all(vec));
	
	//int m = pos[19].size();
	//printf("%lld ", *upper_bound(all(pos[19]), -1));
	int m = vec.size(), now = -1;
	rep(i,m){
		int c = 0;
		rep(j,26){
			int p = *upper_bound(all(pos[j]), now);
			//printf("%lld %lld\n", vec[i], p);
			//printf("%c %lld\n", ('a'+j), p);
			if(vec[i] <= p){c = j;now = p;break;}
		}
		ans.pb(c);
	}
	
	for(int x: ans){
		printf("%c", x+'a');
	}
	printf("\n");
	return 0;
}



