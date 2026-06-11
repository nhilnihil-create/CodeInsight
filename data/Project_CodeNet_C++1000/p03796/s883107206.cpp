#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	long long n,an=1;
	cin>>n;
	n++;
	while(--n)an=(an*n)%1000000007;
	cout<<an<<endl;
}

