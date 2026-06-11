#include<bits/stdc++.h>
#define ll long long
using namespace std;
deque<int>a,b;
ll n;int ly;
void work(ll n)
{
	if (n!=1)
	{
		work(n/2);
		a.push_back(++ly),b.push_back(ly);
		if (n&1) a.push_front(++ly),b.push_back(ly);
	}
}
int main()
{
	scanf("%lld",&n);
	work(n+1);
	printf("%d\n",a.size()*2);
	for (int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	for (int i=0;i<b.size();i++)
		printf("%d ",b[i]);
}