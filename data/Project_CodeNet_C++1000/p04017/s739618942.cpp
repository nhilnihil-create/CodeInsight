#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N,X[100005],L;
int des[20][100005];
signed main(){
	cin>>N;
	rep(i,N)cin>>X[i];
	cin>>L;
	rep(i,N){
		des[0][i]=upper_bound(X,X+N,X[i]+L)-X-1;
	}
	rep(i,19)rep(j,N)des[i+1][j]=des[i][des[i][j]];
	int Q;cin>>Q;
	while(Q--){
		int a,b;cin>>a>>b;a--;b--;
		if(a>b)swap(a,b);
		int ans=0;
		for(int i=19;i>=0;i--){
			if(des[i][a]<b){
				a=des[i][a];ans+=1<<i;
			}
		}
		cout<<ans+1<<endl;
	}
}
