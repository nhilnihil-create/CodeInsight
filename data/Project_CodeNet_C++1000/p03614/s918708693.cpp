#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<62;
const double eps=1e-9;
const ll MOD=1000000007LL;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=0;i<n;i++){
		if(i+1==a[i]){
			ans++;
			if(i<n-1)swap(a[i],a[i+1]);
		}
	}
	cout<<ans<<endl;
}