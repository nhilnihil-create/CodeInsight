#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

bool f(string a,string b)
{
	if(a.size()<
	
	b.size())return 0;
	else if(a.size()>b.size())return 1;
	return a>b;
	
}
int main()
{
	
	string a,b;
	cin>>a>>b;
	if(a==b)cout<<"EQUAL"<<endl;
else	if(f(a,b))cout<<"GREATER"<<endl;
else	cout<<"LESS"<<endl;
}

