#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll read (){
	ll ret=0,w=0;char c=getchar ();
	while (c>'9'||c<'0')w=(c=='-'?1:0),c=getchar();
	while (c<='9'&&c>='0')ret=ret*10+c-'0',c=getchar();
	return w==1?-ret:ret;
}

ll n,x,d;

ll gcd (ll a,ll b){
	if (a%b==0)return b;
	return gcd(b,a%b);
}

int main (){
	n=read();
	x=read();
	d=gcd(n,x);
//	cout<<d<<endl;
	cout<<(n/d-1)*3*d;
	return 0;
}
