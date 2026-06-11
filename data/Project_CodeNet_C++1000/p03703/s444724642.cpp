#include<bits/stdc++.h>
using namespace std;

long long n,k,A[200050],fw[200050];

void update(long long p, long long v)
{
	for(; p<=n; p+=p&(-p)) 
		fw[p]+=v;
}

long long query(long long p)
{
	long long ans=0;
	for(; p; p-=p&(-p)) 
		ans+=fw[p];
	return ans;
}

int main()
{
	cin>>n>>k;
	vector<long long> v;
	for(long long i=1; i<=n; i++)
	{
		cin>>A[i];
		A[i]+=A[i-1];
		v.push_back(A[i]-k*i);
	}
	sort(v.begin(), v.end());
	long long ans=0;
	for(long long i=0; i<=n; i++)
	{
		long long val=lower_bound(v.begin(), v.end(), A[i]-k*i)-v.begin()+1;
		ans+=query(val);
		update(val,1);
	}
	cout<<ans;
}
