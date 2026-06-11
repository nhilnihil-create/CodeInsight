#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MOD 1000000007
#define ll long long
using namespace std;
ll n;
ll f[5100][5100],len;
char s[5100];

ll ksm(ll a,ll b){
	b%=MOD;a%=MOD;
	ll ans=1;
	while(b){
		if (b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;b>>=1;
	}
	return ans;
}

int main(){
	cin>>n;
	scanf("%s",s);
	len=strlen(s);
	f[1][1]=2;f[1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i+1][j+1]=(f[i+1][j+1]+2*f[i][j])%MOD;
			f[i+1][max(0,j-1)]=(f[i+1][max(0,j-1)]+f[i][j])%MOD;
		}
	}
	cout<<f[n][len]*ksm(ksm(2,len),MOD-2)%MOD<<endl;
	return 0;
}