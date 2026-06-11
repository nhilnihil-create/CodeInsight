#include<bits/stdc++.h>
using namespace std;
bool et(vector<long long> &v,long long A,long long B,long long T)
{
	long long bt=0;
	for(int i=0;i<v.size();i++)
	{
		long long tmp=max((long long)0,(v[i]-B*T));
            bt+=(tmp+(A-B)-1)/(A-B);
		
	}

	

	if(bt<=T)
	{
		return true;
	}
	else
	{
		return false;
	}
}
main()
{
	long long N,A,B;
	cin>>N>>A>>B;
	vector<long long> v(N);
	long long mt=-1;
	for(int i=0;i<N;i++)
		{cin>>v[i];
			mt=max(mt,v[i]);
		}

	long long l= 0;
	long long r= mt/B;
	r+=1;
	while((r-l)>1)
	{
		long long mid=(l+r)/2;
		if(et(v,A,B,mid))
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}

	cout<<r<<"\n";

}