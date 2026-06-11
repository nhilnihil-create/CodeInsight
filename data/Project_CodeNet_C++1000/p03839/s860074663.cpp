#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#define ll long long
#define MP make_pair
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
int n,m;
ll a[100010];
ll po[100010];
ll ne[100010];
ll sum=0;
ll res=0;
int main()
{
	cin >>n>>m;
	for (int i=0;i<n;i++)
	{
		cin >>a[i];
		sum+=a[i];
		if (a[i]>0) po[i+1]=po[i]+a[i];
		else po[i+1]=po[i];
		if (a[i]<0) ne[i+1]=ne[i]+a[i];
		else ne[i+1]=ne[i];
	}
	for (int i=0;i<=n-m;i++)
	{
		ll t=po[i+m]-po[i]+ne[i+m]-ne[i];
		t+=po[i]+po[n]-po[i+m];
		res=max(res,t);
		t=po[i]+po[n]-po[i+m];
		res=max(res,t);
	}
	cout <<res;
	return 0;
}