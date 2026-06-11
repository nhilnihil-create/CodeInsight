#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int f[5010][5010],n,m;
char s[5010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;m=strlen(s);
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			f[i][j]=2*f[i-1][j+1]%mod;
			if(j)f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
			else f[i][j]=(f[i][j]+f[i-1][j])%mod;
		}
	}
	cout<<f[n][m]<<'\n';
	return 0;
}
