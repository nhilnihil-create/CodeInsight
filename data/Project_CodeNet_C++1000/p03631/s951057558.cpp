#include<bits/stdc++.h>
using namespace std;
char a[3];
int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c='-'){f=-1;}c=getchar();}
	
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main()
{cin>>a;
	if(a[0]==a[2])cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
	
}