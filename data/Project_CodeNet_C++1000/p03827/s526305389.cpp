#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	int a=0,n,an=0;
	cin>>n;
	string s;
	cin>>s;
	for( auto i: s)
	{a+=i=='I'?1:-1;
		
		an=max(an,a);
		}
	cout<<an<<endl;
}

