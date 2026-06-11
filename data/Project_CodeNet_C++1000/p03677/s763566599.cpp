#include <bits/stdc++.h>
using namespace std;

#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define per(i,n) for (int i=(int)(n)-1;i>=0;i--)
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define Rep(i,n) for (int i=0;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define fore(i,x) for (auto &i:x)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define pii pair<int,int>
#define vi vector <int>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=1e5+3;

ll n,m,ACC;
ll acc[MAXN*2],a[MAXN];
ll ans,ms,k[MAXN],v[MAXN*2],now,V;

inline ll ov(const ll &x){
	if (x>m) re x-m;
	re x;
}

int main(){
	fio;
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n-1){
		int l=a[i],r=a[i+1];
		if (r<l) r+=m;
		acc[l+1]++;
		acc[r+1]--;
		ans+=r-l;
		v[r+1]-=(r-l);
	}
	For(i,m*2){
		int ii=ov(i);
		now+=ACC;
		ACC+=acc[i];
		now+=v[i];
		k[ii]+=now;
	}
	For(i,m){
		cmax(ms,k[i]);
	}
	cout<<ans-ms<<endl;
	re 0;
}