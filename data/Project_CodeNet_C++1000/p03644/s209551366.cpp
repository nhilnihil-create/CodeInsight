#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int main()
{
	
int n,an=1;
cin>>n;
while(an*2<=n)an<<=1;
cout<<an<<endl;

}

