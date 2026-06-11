#include <bits/stdc++.h>
using namespace std;
char p[100011];
int s[100011],q[100011],n;
int main()
{
	cin >>n;
	cin >>p;
	for(int i=0;p[i];i++)
	{
		if(p[i]=='o')
		q[i+1]=0;
		else
		q[i+1]=1;
	}
	q[n+1]=q[1];
	for(int i=0;i<8;i++)
	{
		s[0]=i&1;
		s[1]=(i>>1)&1;
		s[2]=(i>>2)&1;
		for(int j=2;j<=n+1;j++)
		s[j+1]=s[j-2]^q[j];
		if(s[0]^s[n]^s[1]^s[n+1]||s[1]^s[n+1]^s[2]^s[n+2])
		continue;
		for(int j=1;j<=n;j++)
		cout <<(s[j]^s[j-1]?"W":"S");
		cout <<endl;
		return 0;
	}
	puts("-1");
	return 0;
}