#include<bits/stdc++.h>
using namespace std;
long long s[100000],f[100000];
int main(){
	long long n,a,b,k,p,q=0;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	for(int i=1;i<n;i++)
	{
		k=s[i+1]-s[i];
		p=k*a;
		if(p>b)
		{
			f[i]=b;
		}
		else f[i]=p;
	}
	for(int i=1;i<n;i++)
	q+=f[i];
	cout<<q<<endl;
	return 0;
}