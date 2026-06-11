#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	long long s,k,an=0;
	cin>>k>>s;
	for(int i=0;i<=k;i++)
	for(int j=0;j<=k;j++)
	if((s-i-j)<=k&&(s-i-j)>=0)an++;
	cout<<an<<endl;
}

