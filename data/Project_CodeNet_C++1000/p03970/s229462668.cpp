#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char c[16];
const char v[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int s;
int main()
{
	scanf("%s",c);
	for(int i=0;i<16;i++)if(c[i]!=v[i])s++;
	printf("%d\n",s);
	return 0;
}