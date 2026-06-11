#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const ll LINF=1e18;
const int MOD=1e9+7;
//const int MOD=998244353;

int n,m;
ll k;
ll x[100001];
int a[100001],g[100001],gk[100001],T[100001];
ll ans[100001];

int main(){
	cin>>n;
	FOR(i,0,n) cin>>x[i];
	ROF(i,0,n-1) x[i+1]-=x[i];
	cin>>m>>k;
	FOR(i,0,n-1) g[i]=i;
	FOR(i,0,m){
		cin>>a[i];
		swap(g[a[i]-2],g[a[i]-1]);
	}
	FOR(i,0,n-1){
		if(T[i]>0) continue;
		int st=i,t=0;
		do{
			st=g[st];
			t++;
		}while(i!=st);
		st=i;
		do{
			st=g[st];
			T[st]=t;
		}while(i!=st);
	}

	fill(gk,gk+n-1,-1);
	FOR(i,0,n-1){
		if(gk[i]!=-1) continue;
		int kmod=k%T[i];
		int st=i;
		FOR(j,0,kmod){
			st=g[st];
		}
		int st2=i;
		FOR(j,0,T[i]){
			gk[st2]=st;
			st2=g[st2];
			st=g[st];
		}
	}
	ans[0]=x[0];
	FOR(i,0,n-1){
		ans[i+1]=ans[i]+x[gk[i]+1];
	}
	/**
	FOR(i,0,n-1) cout<<g[i]<<" \n"[i==n-2];
	FOR(i,0,n-1) cout<<T[i]<<" \n"[i==n-2];
	FOR(i,0,n-1) cout<<gk[i]<<" \n"[i==n-2];
	**/
	FOR(i,0,n){
		co(ans[i]);
	}
}
