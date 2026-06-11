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
int main(){
	int n;
	int ans=0;
	cin >>n;
	int a,b;
	ll c;
	vector<vector<pair<int,ll>>>path(n);
	rep(i,n-1){
		cin>>a>>b>>c;
		a--;
		b--;
		path[a].emplace_back(b,c);
		path[b].emplace_back(a,c);
	}
	int q,k;
	int x,y;
	cin>>q>>k;
	vector<ll>dis(n,-1LL);
	queue<int>Q;
	int at;
	Q.push(k-1);
	dis[k-1]=0LL;
	while(!Q.empty()){
		at=Q.front();
		Q.pop();
		repi(itr,path[at]){
			if(dis[itr->F]==-1LL){

			Q.push(itr->F);
			dis[itr->F]=dis[at]+(itr->S);
			}
		}
	}
	rep(i,n){
		clog<<" ("<<dis[i]<<endl;
	}
	rep(i,q){
		cin>>x>>y;
		x--;
		y--;

		cout << dis[x]+dis[y] << endl;
	}
	
}