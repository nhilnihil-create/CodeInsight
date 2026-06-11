#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k=0;
	char b[16];
	string a="CODEFESTIVAL2016";
	for(int i=0;i<16;i++)
	{
		cin>>b[i];
		if(a[i]!=b[i])k++;
	}
	cout<<k<<endl;
	return 0;
}