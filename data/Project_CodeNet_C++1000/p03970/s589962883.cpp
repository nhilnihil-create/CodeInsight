#include<bits/stdc++.h>
using namespace std;
string st,st2="CODEFESTIVAL2016";
int g;
int main()
{
	cin>>st;
	for(int i=0; i<16; i++)
	{
		if(st[i]!=st2[i])g++;
	}
	cout<<g<<endl;
	return 0;
}