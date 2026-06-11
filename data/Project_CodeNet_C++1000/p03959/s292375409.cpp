#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using Graph=vector<vector<int>>;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod=1000000007;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
int roundup(int a,int b){return	(a-1)/b+1;}
void YN(bool flg){cout<<(flg?"YES":"NO")<<endl;}
void Yn(bool flg){cout<<(flg?"Yes":"No")<<endl;}
void yn(bool flg){cout<<(flg?"yes":"no")<<endl;}


signed main(){
	int N;cin>>N;
	vector<P> V(N);
	vector<int> T(N);
	rep(i,N) cin>>T[i];
	V[N-1]=P(T[0],T[0]);
	rep(i,N-1){
		if(T[i+1]>T[i]) V[N-i-2]=P(T[i+1],T[i+1]);
		else V[N-i-2]=P(0,T[i]);
	}
	vector<int> A(N);
	rep(i,N) cin>>A[N-i-1];
	V[0].first=max(A[0],V[0].first);
	V[0].second=min(A[0],V[0].second);
	rep(i,N-1){
		if(A[i+1]>A[i]){
			V[i+1].first=max(A[i+1],V[i+1].first);
			V[i+1].second=min(A[i+1],V[i+1].second);
		}
		else{
			V[i+1].second=min(A[i],V[i+1].second);
		}
	}
	//rep(i,N) cout<<V[i].first<<" "<<V[i].second<<endl;
	int ans=1;
	rep(i,N){
		int state=(V[i].first!=0);
		ans*=max(0LL,V[i].second-V[i].first+state);
		ans%=mod;
		}
	cout<<ans<<endl;
}