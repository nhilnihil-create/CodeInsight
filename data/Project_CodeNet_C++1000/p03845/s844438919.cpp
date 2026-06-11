#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> T(N);
	int sum=0;
	rep(i,N)
	{	
		cin>>T[i];
		sum+=T[i];
	}
	int M;
	cin>>M;
	rep(i,M)
	{
		int p,x;
		cin>>p>>x;
		p--;
		cout<<sum-T[p]+x<<endl;
	}
	return 0;
}
