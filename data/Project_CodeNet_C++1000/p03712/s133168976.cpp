#include<bits/stdc++.h>
using namespace std;
int a,b;
string n;
int main()
{
	cin>>a>>b;
	for(int s=0;s<b+2;s++)cout<<"#";
	cout<<endl;
	for(int s=0;s<a;s++)
	{
		cout<<"#";
		cin>>n;
		cout<<n<<"#"<<endl;
	}
	for(int s=0;s<b+2;s++)cout<<"#";
	cout<<endl;
}
