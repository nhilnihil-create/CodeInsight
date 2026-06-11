#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	int is_reverse=0;
	deque<int> deq;
	rep(i,N)
	{
		int a;
		cin>>a;
		if(is_reverse)
		{
			deq.push_front(a);
		}
		else
		{
			deq.push_back(a);
		}
		(is_reverse+=1)%=2;
	}
	rep(i,N)
	{
		if(is_reverse) cout<<deq.back();
		else cout<<deq.front();
		if(i!=N) cout<<" ";
		if(is_reverse) deq.pop_back();
		else deq.pop_front();
	}
	cout<<endl;
	return 0;
}
