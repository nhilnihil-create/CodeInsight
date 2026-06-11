#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long s;
string st;
char ch[18]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int main()
{
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]!=ch[i]) s++;
	}
	cout<<s;
	return 0;
}