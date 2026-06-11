#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int main()
{    
	string a;
	cin>>a;
	if(a.size()%2!=0)
	{
		cout<<"No";
		return 0;
	}
	for(int i=1;i<=a.size()/2;i++)
	{
		if((a[i-1]=='p'&&a[a.size()-i]!='q')||(a[i-1]=='q'&&a[a.size()-i]!='p')||(a[i-1]=='q'&&a[a.size()-i]!='p')||(a[i-1]=='p'&&a[a.size()-i]!='q'))
		{
			cout<<"No"<<endl;
			return 0;
		}
		if((a[i-1]=='b'&&a[a.size()-i]!='d')||(a[i-1]=='d'&&a[a.size()-i]!='b')||(a[i-1]=='d'&&a[a.size()-i]!='b')||(a[i-1]=='b'&&a[a.size()-i]!='d'))
		{
			cout<<"No"<<endl;
			return 0;
		}
		//cout<<a[i-1]<<" "<<a[a.size()-i]<<endl;
	}
	cout<<"Yes"<<endl;
	return 0;
}