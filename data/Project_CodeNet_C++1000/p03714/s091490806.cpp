#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int Maxn = 1e6;
const ll MAX=-1e18;

ll dp_f[Maxn],dp_e[Maxn],a[Maxn];

priority_queue<ll,vector<ll>,greater<ll> > que;
priority_queue<ll>pque;

void Slove_f(int n){
	ll sum_f=0;
	for(int i=1;i<=3*n;i++){
		que.push(a[i]);
		sum_f+=a[i];
		dp_f[i]=sum_f;
		if(que.size()>n){
			sum_f -= que.top();
			que.pop();
			dp_f[i] =sum_f;
		}
	}
}

void Slove_e(int n){
	ll sum_e=0;
	for(int i=3*n;i>=1;i--){
		pque.push(a[i]);
		sum_e+=a[i];
		dp_e[i]=sum_e;
		if(pque.size()>n){
			sum_e-=pque.top();
			pque.pop();
			dp_e[i]=sum_e;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++) scanf("%lld",&a[i]);

	Slove_f(n);
	Slove_e(n);

	ll ans=MAX;
	for(int i=n;i<=2*n;i++){
		ans=max(ans,dp_f[i]-dp_e[i+1]);
	}
	printf("%lld\n",ans);
}