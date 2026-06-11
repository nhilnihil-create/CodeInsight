#include <bits/stdc++.h>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
#define fcout cout<<fixed<<setprecision(10)
using namespace std;
//
const int INF=1e9+7;
const int MOD=1e9+7;
//
int main(){
	int n; cin>>n;
	int a[300][300];
	int b[300][300];
	FOR(i,0,n){
		FOR(j,0,n){
			cin>>a[i][j];
			b[i][j]=1;
		}
	}
	bool f=true;
	FOR(k,0,n) FOR(i,0,n) FOR(j,0,n){
		if(i==j||j==k||k==i) break;
		if(a[i][k]+a[k][j]<a[i][j]){
			f=false;
		}else if(a[i][k]+a[k][j]==a[i][j]){
			b[i][j]=0;
			b[j][i]=0;
		}
		if(a[i][j]+a[j][k]<a[i][k]){
			f=false;
		}else if(a[i][j]+a[j][k]==a[i][k]){
			b[i][k]=0;
			b[k][i]=0;
		}
		if(a[j][i]+a[i][k]<a[j][k]){
			f=false;
		}else if(a[j][i]+a[i][k]==a[j][k]){
			b[k][j]=0;
			b[j][k]=0;
		}
			
	}
	ll ans=0;
	FOR(i,0,n) FOR(j,0,n) if(b[i][j]) ans+=a[i][j];
	if(f) co(ans/2);
	else co(-1);
	
}
