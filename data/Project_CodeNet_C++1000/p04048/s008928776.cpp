#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,x,light;

void FindLight(ll Long,ll Short)
{
	if(Long%Short==0)
	{
		light+=((Long<<1)-Short);
		return;
	}
	light+=(Long/Short*Short*2);
	FindLight(Short,Long%Short);
}

int main()
{
	cin>>n>>x;
	light=n;
	if(x>=n-x) FindLight(x,n-x);
		else FindLight(n-x,x);
	cout<<light<<"\n";
}