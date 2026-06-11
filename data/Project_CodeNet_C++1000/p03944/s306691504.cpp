#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	int x[2],y[2],xx,yy,n,a;
	x[0]=0;y[0]=0;
	cin>>x[1]>>y[1]>>n;
	while(n--)
	{cin>>xx>>yy>>a;
		if(a==1)x[0]=max(x[0],xx);
			else if(a==2)x[1]=min(x[1],xx);
			else if(a==3)y[0]=max(y[0],yy);
			else y[1]=min(y[1],yy);
		
		
		
		
	}
	cout<<max(0,y[1]-y[0])*max(0,x[1]-x[0])<<endl;
	
	
}

