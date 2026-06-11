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

int N;
P X[505];
int ans[500*505];
signed main(){
	cin>>N;
	REP(i,N+1){
		cin>>X[i].first;X[i].second=i;
		ans[X[i].first]=i;
	}
	sort(X+1,X+N+1);
	REP(i,N+1){
		int j=X[i].second-1,k=1;
		while(j&&k<X[i].first){
			if(!ans[k]){
				ans[k]=X[i].second;j--;
			}
			k++;
		}
		if(j){
			cout<<"No"<<endl;return 0;
		}
	}
	for(int i=N;i>0;i--){
		int j=N-X[i].second,k=N*N;
		while(j&&k>X[i].first){
			if(!ans[k]){
				ans[k]=X[i].second;j--;
			}
			k--;
		}
		if(j){
			cout<<"No"<<endl;return 0;
		}
	}
	cout<<"Yes"<<endl;
	REP(i,N*N+1)cout<<ans[i]<<" ";
	cout<<endl;
}
