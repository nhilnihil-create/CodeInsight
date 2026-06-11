#include<bits/stdc++.h>
#define LL long long
#define maxn 1000000

using namespace std;

const LL MOD = 1e9+7;

LL fact[maxn+5];	//阶乘
LL a[maxn+10];	// 乘法逆元
//LL inv[maxn+10];	//快速幂

LL pow(LL x)
{
	LL n = MOD-2;
    LL res=1;
	while(n>0)
	{
	   if(n%2==1)
	   	 res=res*x%MOD;
	   x=x*x%MOD;
	   n>>=1;
	}
	return res;
}

void init(){
    a[0] = a[1] = 1;
    fact[0] = fact[1] = 1;

    for(int i = 2; i <= 1000005; i++)
    {
        fact[i] = fact[i-1] * i % MOD;
		a[i] = a[i-1] * pow(i) % MOD;	//m!的MOD次方 = (m-1)!的MOD次方 * m的MOD次方

    }
}

LL C(LL n, LL m){	//乘法逆元
	if(n<0||m<0||n<m)return 0;
    return fact[n]*a[n-m]%MOD*a[m]%MOD;
}

int main()
{
    init();
	LL n,m,a,b;
	cin>>n>>m>>a>>b;
	LL sum=0;
	for(int i=b+1;i<=m;i++)
    {
        sum+=(C(n-a+i-2,i-1)*C(a+m-i-1,m-i))%MOD;
        sum%=MOD;
    }
    cout<<sum%MOD<<endl;


}
