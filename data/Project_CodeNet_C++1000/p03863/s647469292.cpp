#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	if(a[0]!=a[a.length()-1])
	{
		if((a.length()-1)%2==1) cout<<"Second"<<endl;
		else cout<<"First"<<endl;
	}
	if(a[0]==a[a.length()-1])
	{
		if((a.length()-1)%2==0) cout<<"Second"<<endl;
		else cout<<"First"<<endl;
	}
	return 0;
}