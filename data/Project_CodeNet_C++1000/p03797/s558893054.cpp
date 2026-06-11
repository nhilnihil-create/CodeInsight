#include <bits/stdc++.h>
using namespace std;
int main()
 
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long int n,m,rem,msize=0;
	cin>>n >>m;
	if(n*2<=m)
	{
		rem=m-n*2;
		if(rem>=4)
		{
			while(rem!=0)
	
		{  
			msize++;
			rem=rem-4;
		}

      	cout<< msize+n;
		}
		else
		{
			cout << n;
		}
	
	}
	else
	
	{
		m=m/2;
		msize=+m;
		cout<<msize;
	}
	
	

}