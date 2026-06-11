#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
ll n;int cnt;
deque<int> Q1,Q2;
void Work(ll n)
{
	if(n==1)return;
	Work(n>>1);++cnt;
	Q1.push_front(cnt);Q2.push_front(cnt);
	if(n&1)++cnt,Q1.push_front(cnt),Q2.push_back(cnt); 
}
int main()
{
	cin>>n;Work(n+1);
	printf("%d\n",(int)(Q1.size()+Q2.size()));
	while(!Q1.empty())printf("%d ",Q1.front()),Q1.pop_front();
	while(!Q2.empty())printf("%d ",Q2.front()),Q2.pop_front();
	puts("");return 0;
}
