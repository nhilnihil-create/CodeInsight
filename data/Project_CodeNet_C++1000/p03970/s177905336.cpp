#include<bits/stdc++.h>
using namespace std;
char x[20],y[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int main()
{
	int nu=0;
	cin>>x;
	for(int i=0;i<16;i++)
	if(x[i]!=y[i])nu++;
	cout<<nu<<endl;
	return 0;
}