#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
string a="CODEFESTIVAL2016";
int main()
{
	string n;
	cin>>n;
	int ans=0;
	for(int i=0;i<a.size();i++)
	{
		if(n[i]!=a[i])
			ans++;
	}
	cout<<ans;
	return 0; 
}