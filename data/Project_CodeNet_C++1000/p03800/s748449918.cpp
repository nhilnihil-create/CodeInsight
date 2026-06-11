#include <bits/stdc++.h>
using namespace std;
char dat[100011];
bool zz[100011];
int main()
{
	int n;
	cin >>n;
	cin >>dat;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		zz[0]=i;
		zz[1]=j;
		for(int k=1;k<n-1;k++)
		zz[k+1]=zz[k-1]^zz[k]^(dat[k]=='x');
		if(((dat[n-1]=='x')==(zz[n-2]^zz[n-1]^zz[0]))&&((dat[0]=='x')==(zz[n-1]^zz[0]^zz[1])))
		{
			for(int k=0;k<n;k++)
			cout <<(zz[k]?'W':'S');
			cout <<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}