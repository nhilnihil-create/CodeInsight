#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)

const int INF=1<<30;
typedef long long ll;
using namespace std;

priority_queue<int,vector<int>,greater<int> >Q;
priority_queue<int>q;

const int maxn=300000+10;

ll L[maxn],R[maxn];

int a[maxn];

int main()
{
	int n;cin>>n;
	rep(i,1,n*3) scanf("%d",a+i);

	
	ll sum=0;
	rep(i,1,n) Q.push(a[i]),sum+=a[i]; L[n]=sum;
	rep(i,n+1,2*n)
	{
		if(a[i] > Q.top()) 
		{
			sum-=Q.top();Q.pop();
			sum+=a[i];Q.push(a[i]);
		}
		L[i]=sum;
	}

	
	sum=0;
	for(int i=n*3;i>n*2;--i) q.push(a[i]),sum+=a[i]; R[n*2+1]=sum;
	for(int i=n*2;i>n;--i){
		if(a[i]<q.top())
		{
			sum=sum-q.top()+a[i];
			q.pop();q.push(a[i]);
		}
		R[i]=sum;
	}

//	rep(i,1,n*3) printf("%lld ",L[i]);puts("");
//	rep(i,1,3*n) printf("%lld ",R[i]);puts("");

	ll ans=-1ll<<50;
	rep(i,n,2*n) ans=max(ans,L[i]-R[i+1]);
	cout<<ans<<endl;
	return 0;
}