#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max=1e5+5;
const int Mod=1e9+7;

ll g(int n)
{
	ll res=1;
	for(int i=1;i<=n;i++)
	{
		res*=i;
		res%=Mod;
	}
	return res;
}

int main()
{
	int n,m;
	cin>>n>>m;
	if(abs(m-n)>=2)
	 cout<<0;
	else
	{
		if(n==m)cout<<2*g(n)*g(m)%Mod;
		else cout<<g(n)*g(m)%Mod;
	} 
}