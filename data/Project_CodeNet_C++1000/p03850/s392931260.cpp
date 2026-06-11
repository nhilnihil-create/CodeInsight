#include<bits/stdc++.h>
#define fi first
#define se second
#define bug cout<<"--------------"<<endl
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll inf=1e18;
const ll llf=1e18;
const int mod=1e9+7;
const int maxn=1e5+10;
int n;
ll x;
char c;
ll f[maxn][3]; 
int main(){
	ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	cin>>n>>x;
	f[1][0]=x;
	f[1][1]=f[1][2]=-inf;
	for(int i=2;i<=n;i++){
		cin>>c>>x;
		if(c=='+'){
			f[i][0]=max(f[i-1][0],f[i-1][1])+x;
			f[i][1]=f[i-1][1]-x;
			f[i][2]=f[i-1][2]+x;
		}else{
			f[i][0]=-inf;
			f[i][1]=max(f[i-1][0]-x,f[i-1][1]+x);
			f[i][2]=max(f[i-1][1],f[i-1][2])+x;
		}
	}
	cout<<max({f[n][0],f[n][1],f[n][2]});
	return 0;
}
