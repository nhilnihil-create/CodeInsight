#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	long long a,b,x;
	cin>>a>>b>>x;
	cout<<b/x-a/x+((a%x)==0)<<endl;
	
	
}

