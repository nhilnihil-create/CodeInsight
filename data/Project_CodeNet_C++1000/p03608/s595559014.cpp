#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
//ダイクストラ法:スタートから任意の地点での最短距離、最短パスを求める
//計算量:(頂点+辺)log(頂点) 
//始点,終点,隣接リスト(pathlist[edge.A]=(edgeB,legth))-->距離(notfound:INFLL),previous(notfound:INF);
vector<pair<long long,int>> Dikstra(int start,vector<vector<pair<int,long long>>>&pathlist){
	int edge=pathlist.size();
	pair<long long, int> cerching;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q; //start to distance,[ditance ,islandNo.]
	vector<pair<long long,int>> D(edge,mp(INFLL,INF)); //distance (ans), preious path
	vector<bool>had(edge,false);
	D[start] = mp(0, -1); //distance ,Previous egdg
	q.emplace(0LL, start);
	while (!q.empty()){
		cerching = q.top();
		q.pop();
		if (had[cerching.second] == false){
			had[cerching.second] = true;
			for (auto i = pathlist[cerching.second].begin(); i != pathlist[cerching.second].end(); i++){
				if (had[i->first] == false){
					if(chmin(D[i->first].F, (cerching.first) + (i->second))){
						D[i->first].S=cerching.second;
					}
					q.emplace(D[i->first].F, i->first);
				}
			}
		}
	}
return D;
}
ll func(int at,int state,VV& dis,VV & dp){
	if(dp[at][state]==INFLL){
		rep(i,dis.size()){
			if(state & (1<<i)){
				chmin(dp[at][state],func(i,state&~(1<<i),dis,dp)+dis[at][i]);
			}
		}
	}	
	return dp[at][state];
}
int main(){
	int n,m,r;
	ll ans=INFLL;
	cin >>n>>m>>r;
	Vi com(r);
	rep(i,r){
		cin>>com[i];
		com[i]--;
	}
	int a,b;
	ll c;
	vector<vector<pair<int,ll>>> path(n);
	rep(i,m){
		cin>>a>>b>>c;
		a--;
		b--;
		path[a].emplace_back(b,c);
		path[b].emplace_back(a, c);
	}
	vector<pair<long long, int>>res;
	vector<vector<ll>> dis(r,V(r));
	rep(i,r){
		res.clear();
		res=Dikstra(com[i],path);
		rep(j,r){
			dis[i][j]=res[com[j]].F;
		//	clog<<dis[i][j]<<" ";
		}
	//	clog<<endl;
	}
	VV dp(r,V(1<<r,INFLL));
	rep(i,r){
		dp[i][0]=0LL;
	}
	rep(i,r){
		chmin(ans,func(i,(1<<r )-1,dis,dp));
	}
	cout << ans << endl;
}