#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
//const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
	int n;
	cin>>n;
	V<P> a(n);
	V<int> ans(n*n,-1);
	for(int i=0;i<n;i++){
		cin>>a[i].fi;
		ans[--a[i].fi]=i+1;
		a[i].se=i;
	}
	sort(all(a));
	for(int i=0;i<n;i++){
		 int l=a[i].se;
		 for(int j=0;j<a[i].fi;j++){
			 if(l==0)break;
			 if(ans[j]!=-1)continue;
			 ans[j]=a[i].se+1;
			 l--;
		 }
		 if(l!=0){
			 cout<<"No"<<"\n";
			 return 0;
		 }
	}
	reverse(all(a));
	for(int i=0;i<n;i++){
		int r=n-a[i].se-1;
		 for(int j=a[i].fi+1;j<n*n;j++){
			 if(r==0)break;
			 if(ans[j]!=-1)continue;
			 ans[j]=a[i].se+1;
			 r--;
		 }
		 if(r!=0){
			 cout<<"No"<<"\n";
			 return 0;
		 }
	}
	cout<<"Yes"<<"\n";
	for(int i=0;i<n*n;i++)cout<<ans[i]<<" ";
	cout<<"\n";
}

