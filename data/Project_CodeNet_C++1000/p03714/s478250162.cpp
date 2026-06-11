#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	int N,NN;
	ll res=-1e15,fr=0,br=0;
	priority_queue<ll,vector<ll>,greater<ll> >F;
	priority_queue<ll,vector<ll> >BB;
	vector<ll>C;
	stack<ll>BC;
	queue<ll>FC;
	cin>>N;
	NN=3*N;
	for(int i=0;i<NN;i++)
	{
		ll x;
		cin>>x;
		C.push_back(x);
	}

	//back
	for(int i=NN-1;i>=N-1;i--)
	{
		if(BB.size()>N)
		{
			br-=BB.top();
			BB.pop();
			BC.push(br);
		}
		else if(BB.size()==N)
		{
			BC.push(br);
		}
		BB.push(C[i]);
		br+=C[i];
	}

	//front
	for(int i=0;i<=N*2;i++)
	{
		if(F.size()>N)
		{
			fr-=F.top();
			F.pop();
			FC.push(fr);
		}
		else if(F.size()==N)
		{
			FC.push(fr);
		}
		fr+=C[i];
		F.push(C[i]);
	}



	for(;!FC.empty();)
	{
		res=max(res,FC.front()-BC.top());
		FC.pop();
		BC.pop();
	}

	cout<<res<<endl;
}