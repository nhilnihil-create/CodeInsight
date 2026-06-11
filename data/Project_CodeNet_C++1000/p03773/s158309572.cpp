#include<bits/stdc++.h>
using namespace std;
int a,b;
int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c='-'){f=-1;}c=getchar();}
	
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main()
{cin>>a>>b;
	cout<<(a+b)%24<<endl;
	return 0;
	
}