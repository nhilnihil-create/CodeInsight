#include<iostream>
using namespace std;
string n1,n2="CODEFESTIVAL2016";
int ans;
int main()
{
	cin>>n1;
	for(int i=0;i<16;i++)
	 if(n1[i]!=n2[i])++ans;
	cout<<ans<<endl;
}