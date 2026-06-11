#include <bits/stdc++.h>

#define int long long

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)a, i##_len=(b); i<i##_len; i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define all(box) box.begin(), box.end()

using namespace std;

using P = pair<int,int>;
using ll = long long;

const long long INF = LLONG_MAX/3;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dp[5010][5010]={},dpr[5010][5010]={};
signed main(){
	int n,k;
	cin>>n>>k;
	int a[5010];
	rep(i,n){
		cin>>a[i];
	}
	dp[0][0]=true;
	dpr[0][0]=true;
	rep(i,1,n+1){
		rep(j,k)dp[i][j]=dp[i-1][j];
		rep(j,k){
			if(dp[i-1][j]){
				if(j+a[i-1]<k)dp[i][j+a[i-1]]=true;
			}
		}
	}
	rep(i,1,n+1){
		rep(j,k)dpr[i][j]=dpr[i-1][j];
		rep(j,k){
			if(dpr[i-1][j]){
				if(j+a[n-i]<k)dpr[i][j+a[n-i]]=true;
			}
		}
	}
	int cnt=0;
	rep(i,n){
		int mn=INF;
		vector<int> s,t;
		rep(j,k){
			if(dp[i][j])s.push_back(j);
			if(dpr[n-i-1][j])t.push_back(j);
		}
		/*cout<<"s:";
		rep(j,s.size())cout<<s[j]<<" ";
		cout<<endl;
		cout<<"t:";
		rep(j,t.size())cout<<t[j]<<" ";
		cout<<endl;*/
		rep(j,s.size()){
			int l=lower_bound(t.begin(),t.end(),k-s[j]-a[i])-t.begin();
			if(l<t.size())chmin(mn,s[j]+a[i]+t[l]);
		}
		if(mn==INF||mn-a[i]>=k)cnt++;
	}
	cout<<cnt<<endl;
}
