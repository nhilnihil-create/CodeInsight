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

int N,M;
int A[100005];
int sum[200005],sum2[200005];
signed main(){
	cin>>N>>M;
	int ans=0;
	rep(i,N){
		cin>>A[i];A[i]--;
		if(i){
			sum[A[i-1]+2]++;
			if(A[i-1]<A[i]){
				int p=A[i]-A[i-1];
				ans+=p;
				sum[A[i]+1]-=p;
				sum[A[i]+2]+=p-1;
			}
			else {
				int p=A[i]+M-A[i-1];
				ans+=p;
				sum[A[i]+M+1]-=p;
				sum[A[i]+M+2]+=p-1;
			}
		}
	}
	rep(i,2*M)sum[i+1]+=sum[i];
	int mx=0;
	rep(i,2*M){
		sum2[i%M]+=sum[i];
		sum[i+1]+=sum[i];
	}
	rep(i,M)chmax(mx,sum2[i]);
	cout<<ans-mx<<endl;
}
