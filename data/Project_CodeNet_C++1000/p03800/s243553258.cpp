#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool zz[100000];
int main(){
	int n;
	cin>>n>>s;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		zz[0]=i;
		zz[1]=j;
		for(int k=1;k<n-1;k++)
		{
			zz[k+1]=zz[k-1]^zz[k]^(s[k]=='x');
		}
		if((s[n-1]=='x')==(zz[n-2]^zz[n-1]^zz[0])&&(s[0]=='x')==(zz[n-1]^zz[0]^zz[1]))
		{
			for(int k=0;k<n;k++)
			cout<<(zz[k]?'W':'S');
			return 0; 
		}
	}
	cout<<-1;
	return 0;
}
