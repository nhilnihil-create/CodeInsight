#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using lint=int64_t;
using namespace std;

int main()
{
	int N;
	lint a[300010]={};
	priority_queue<int,vector<int>,greater<int>> ql;
	priority_queue<int> qr;
	lint qsum;
	lint lsum[100010]={};
	lint rsum[100010]={};
	lint ans=-1e18;
	
	cin >> N;
	for(int i=0;i<3*N;i++)
		cin >> a[i];
	
	qsum=0;
	for(int i=0;i<N;i++)
	{
		ql.push(a[i]);
		qsum+=a[i];
	}
	lsum[0]=qsum;
	for(int i=0;i<N;i++)
	{
		ql.push(a[N+i]);
		qsum+=a[N+i];
		
		qsum-=ql.top();
		ql.pop();
		lsum[i+1]=qsum;
	}
	
	qsum=0;
	for(int i=0;i<N;i++)
	{
		qr.push(a[3*N-i-1]);
		qsum+=a[3*N-i-1];
	}
	rsum[N]=qsum;
	for(int i=0;i<N;i++)
	{
		qr.push(a[2*N-i-1]);
		qsum+=a[2*N-i-1];
		
		qsum-=qr.top();
		qr.pop();
		rsum[N-i-1]=qsum;
	}
	
	for(int i=0;i<=N;i++)
		ans=max(ans,lsum[i]-rsum[i]);
	
	cout << ans << endl;
	return 0;
}