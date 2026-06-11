#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 1000005
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
const long long inf = 2e18;
int n,f[maxn],sum[maxn];
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen(".inp","r",stdin); freopen(".out","w",stdout);
	//freopen("inp.txt","r",stdin);
	cin>>n; int i,j,k;
	f[n]=n; sum[n+1]=0; sum[n+2]=0; sum[n]=n;
	for (i=n-1;i>=1;i--){
		f[i]=f[i+1];
		f[i]+=sum[i+3];
		f[i]+=(n-1)*(n-1);
		j=n-(i+3)+1; if (j<0) j=0; j=(n-1-j);
		f[i]+=j; f[i]%=mod;
		sum[i]=sum[i+1]+f[i]; sum[i]%=mod;
	}
	cout<<f[1];
	
}