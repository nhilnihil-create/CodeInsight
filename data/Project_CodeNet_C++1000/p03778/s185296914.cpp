#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	int w,a,b;
	cin>>w>>a>>b;
	cout<<max({0,b-a-w,a-b-w})<<endl;
}

