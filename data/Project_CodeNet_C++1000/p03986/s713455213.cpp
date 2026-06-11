#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string X;
	cin>>X;
	int N=X.size();
	int s=0;
	int dec=0;
	rep(i,N)
	{
		if(X[i]=='S')
		{
			s++;
		}
		else
		{
			if(s>0) 
			{
				dec++;
				s--;
			}
		}
	}
	cout<<N-dec*2<<endl;
	return 0;
}
