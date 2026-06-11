#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,both,number;
bool a[100010];
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
		a[i]=false;
	for(int i=1; i<=n; i++)
	{
		cin>>number;
		if(a[number]==true)both++;
		else a[number]=true;
	}
	if(both%2==1)both++;
	cout<<n-both;
	return 0;
}