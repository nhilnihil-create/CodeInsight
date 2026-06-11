#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int n,k;
int used[111111];
int mp[111111];
int a[111111];
int dist[111111];
vector<vector<int>> v(111111);

int bfsa(){
	queue<pair<int,int>> que;
	
	REP(i,n)dist[i] = -1;
	que.push(MP(0,0));
	
	while(!que.empty()){
		auto now = que.front();que.pop();
		if(dist[now.FI] != -1)continue;
		dist[now.FI] = now.SE;
		REP(i,v[now.FI].size()){
			que.push(MP(v[now.FI][i], now.SE+1));
		}
	}
}

int main(){
	
	REP(i,111111)used[i] = -1;
	cin >> n >> k;
	
	REP(i,n){
		cin >> a[i],a[i]--;
		mp[a[i]]++;
		v[a[i]].PB(i);
	}
	bfsa();
	int ans = 0;
	if(a[0] != 0)ans++;
	used[0] = 0;
	a[0] = 0;
	
	priority_queue<pair<int,int>> pq;
	
	REP(i,n)pq.push(MP(dist[i],i));
	while(!pq.empty()){
		auto tmp = pq.top();pq.pop();
		int now = tmp.SE;
		//cout << now << endl;
		if(used[now] != -1 || k >= dist[now])continue;
		int cou = 0;
		while(1){
			//cout << " " << now << endl;
			if(used[now] > cou)break;
			used[now] = cou;
			if(now == 0)break;
			cou++;
			if(cou == k && a[now] != 0){
				a[now] = 0;
				ans++;
			}
			now = a[now];
		}
	}
	
	cout << ans << endl;
		
	return 0;
}
