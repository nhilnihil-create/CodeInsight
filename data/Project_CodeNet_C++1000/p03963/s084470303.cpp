#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int i[256];
int main()
{
	int n,k,an;
	cin>>n>>k;
	an=k;
	k--;n--;
	while(n-->0)an*=k;
	cout<<an<<endl;
	
	
}

