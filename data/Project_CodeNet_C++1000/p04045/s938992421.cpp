#include<bits/stdc++.h>
using namespace std;
int d[10];
int f(int n)
{
	if(n==0)return d[0]==0;
	while(n)
	{
		if(d[n%10])return 0;
		n/=10;
	}
	return 1;
	
}
int main()
{
int n,m,a;
cin>>n>>m;
while(m--){cin>>a;d[a]=1;}
for(;;n++)
if(f(n))return 0 & printf("%d\n",n);
}

