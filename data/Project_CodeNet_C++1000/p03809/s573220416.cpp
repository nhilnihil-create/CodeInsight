#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9+7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}

vector<int>g[100010];
vector<int> a;
int s ;
int flg = 0;

int dfs(int now,int par){
		int ret = 0;
		if(g[now].size()==1&&par!=-1)return a[now];
		int cnt = 0,ma = -1;
		for(auto e:g[now]){
			if(par == e)continue;
			int t = dfs(e,now);
			ret += t;
			CHMAX(ma,t);
			cnt++;
		}
		if(par == -1){
			return ret == a[now];
		}
		if(cnt == 1){
			if(ret != a[now]){
				flg = true;
				return 0;
			}
			else return a[now];
		}else{
			if(2 * a[now] - ret < 0)flg = true;
			if(a[now]>ret)flg = true;
			if(a[now]<ma)flg = true;
			return 2 * a[now] - ret;
		}
	};

signed main(){
	int N;
	cin>>N;
	a.resize(N);
	for(auto& e:a)cin >> e;
	vector<int>cnt(N,0);
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
	}
	
	REP(i,N){
		if(cnt[i] == 1)s = i;
	}
	if(dfs(s,-1)){
		if(flg){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}