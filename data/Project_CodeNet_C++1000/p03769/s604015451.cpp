#include <bits/stdc++.h>

#define LL long long
#define N 110

using namespace std;

deque<int> ans1,ans2;
int modify[N],tot;

void solve(LL n)
{
	if(n==1) return;
	if((n-1)%2==0)
	{
		modify[++tot] = 1;
		solve((n-1)/2);
	}
	else
	{
		modify[++tot]=2;
		solve(n-1);
	}
}

int main()
{
	LL n;
	cin>>n;
	int tim=1;
	solve(n);
	ans1.push_back(1);
	for(int i=tot;i>=1;i--)
	{
		if(modify[i]==1) ans1.push_back(++tim);
		else ans1.push_front(++tim);
	}
	cout<<2*(int)ans1.size()<<endl;
	for(int i=0;i<(int)ans1.size();i++) printf("%d ",ans1[i]);
	for(int i=0;i<(int)ans1.size();i++) printf("%d%c",i+1,i==((int)ans1.size())-1? '\n':' ');
	return 0;
}