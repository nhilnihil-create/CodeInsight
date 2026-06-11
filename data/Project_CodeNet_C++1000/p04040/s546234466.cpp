#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll H,W,A,B;
ll jiec[2000010];
ll answ;
void jc()
{
	jiec[1]=1;
	for(ll k=2;k<=2000005;k++)
		jiec[k]=jiec[k-1]*k,jiec[k]%=MOD;
}
ll kzojld(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll answ=kzojld(b,a%b,x,y);
    ll k=y;
    y=x-a/b*y,x=k;
    return answ;
}
ll C(ll x1,ll y1,ll x2,ll y2)
{
	ll all=abs(y2-y1)+abs(x2-x1);
	ll up=abs(y2-y1);
	if(up==0 || all==up)
		return 1;
	ll a1=jiec[all];
	ll a2=jiec[up];
	ll a3=jiec[all-up];
	ll a4=a2*a3+MOD%MOD;
	if(a4<0)
		a4+=MOD;
	ll x=0,y=0;
	kzojld(a4,MOD,x,y);
	ll end0=a1*x%MOD;
	if(end0<0)
		end0+=MOD;
	return end0;
}
int main()
{
	jc();
	scanf("%lld %lld %lld %lld",&H,&W,&A,&B);
	ll hang=A+1;
	for(ll k=B+1;k<=W;k++)
		answ+=C(hang-1,k,1,W)*C(H,1,hang,k),answ%=MOD;
	if(answ<0)
		answ+=MOD;
	printf("%lld",answ);
	return 0;
}