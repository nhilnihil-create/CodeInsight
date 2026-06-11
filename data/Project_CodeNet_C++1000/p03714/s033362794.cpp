#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

typedef long long ll;

ll a[300005];

int main(){

	int N;

	scanf("%d",&N);

	int i;

	for(i=0;i<3*N;i++){
		scanf(" %lld",&a[i]);
	}
	
	priority_queue<ll, vector<ll>, greater<ll> > q1;

	vector<ll>v1(N+1);

	ll sum=0ll;

	for(i=0;i<N;i++){
		q1.push(a[i]);
		sum+=a[i];
	}
	v1[0]=sum;

	for(i=1;i<=N;i++){
	auto in=a[N-1+i];
	q1.push(in);
	auto out=q1.top();q1.pop();
	v1[i]=v1[i-1]+in-out;
	}

	priority_queue<ll, vector<ll>, less<ll> > q2;

	vector<ll>v2(N+1);

	sum=0ll;

	for(i=2*N;i<3*N;i++){
		q2.push(a[i]);
		sum+=a[i];
	}
	v2[N]=sum;

	for(i=N;i>0;i--){
	auto in=a[N-1+i];
	q2.push(in);
	auto out =q2.top();q2.pop();
	v2[i-1]=v2[i]+in-out;
	}

	ll ans=-LLONG_MAX;

	for(i=0;i<=N;i++){
	ans=max(ans,v1[i]-v2[i]);
	}

	printf("%lld\n",ans);

	return 0;
}