#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int tmp=a.find("ST");
	while(a.length()>0&&tmp!=string::npos)
	{
		a.erase(tmp,2);
		int x=max(tmp-1,0);
		tmp=a.find("ST",x);
	}
	cout<<a.length()<<endl;
	return 0;
} 