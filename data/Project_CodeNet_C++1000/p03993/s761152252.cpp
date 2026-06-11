#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> A(N);
	rep(i,N)
   	{
		cin>>A[i];
		A[i]--;
	}
	int ans=0;
	rep(i,N)
	{
		if(A[A[i]]==i&&A[i]>i)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
