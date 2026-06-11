#include <iostream>
using namespace std;
string a;
string b="CODEFESTIVAL2016";
int n,ans;
int main()
{
	cin>>a;
	for(int i=0;i<=15;i++)
	if(a[i]!=b[i])
	ans++;
	cout<<ans<<endl;
    return 0;
}
