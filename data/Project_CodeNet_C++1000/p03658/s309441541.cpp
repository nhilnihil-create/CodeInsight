#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int main()
{
	
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n,greater<int>());
int an=0;
for(int i=0;i<k;i++)an+=a[i];
cout<<an<<endl;

}

