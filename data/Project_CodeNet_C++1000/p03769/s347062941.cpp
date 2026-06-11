#include<bits/stdc++.h>
using namespace std;
int now=0;
long long x;
deque<int>q1,q2;
void solve(long long n)
{
	if(n==1) return;
	solve(n>>1);
	now++,q1.push_front(now),q2.push_front(now);
	if(n&1) now++,q1.push_front(now),q2.push_back(now);
}
int main()
{
	scanf("%lld",&x);
	solve(x+1);
	int s1=q1.size(),s2=q2.size();
	printf("%d\n",s1+s2);
	for(int i=0;i<s1;i++) printf("%d ",q1[i]);
	for(int i=0;i<s2;i++) printf("%d ",q2[i]);
	return 0;
}