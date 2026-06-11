#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
char s[10086];
int main()
{
	cin>>s;
	for(int i=0;i<12;i++)
	{
		if(i==4) cout<<" ";
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}