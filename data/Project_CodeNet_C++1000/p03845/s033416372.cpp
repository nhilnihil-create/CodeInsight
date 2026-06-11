#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	long long n,x,id,m,an=0;
	cin>>n;
	long long a[n+2];
	for(int i=1;i<=n;i++){cin>>a[i];an+=a[i];}
	cin>>m;
	while(m--)
	{cin>>id>>x;
		cout<<an-a[id]+x<<endl;
		
		
	}
	
}

