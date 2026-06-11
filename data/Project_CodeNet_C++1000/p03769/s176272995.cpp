#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
deque<int> l,r;
long long n;
int tot;
void solve(long long x)
{
	if(x==1) return;
	solve(x>>1);
	l.push_front(++tot);
	r.push_front(tot);
	if(x&1)
	{
		l.push_front(++tot);
		r.push_back(tot);
	}
}
int main()
{
	cin>>n;
	solve(n+1);
	cout<<l.size()+r.size()<<endl;
	for(int i=0;i<l.size();i++)
		cout<<l[i]<<' ';
	for(int i=0;i<r.size();i++)
		cout<<r[i]<<' ';
}