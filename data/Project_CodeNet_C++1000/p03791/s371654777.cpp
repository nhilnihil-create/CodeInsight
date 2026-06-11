#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN

ll f(ll n){
	if(n==1)return 1;
	return n*f(n-1)%MOD;
}

int main(void){
	ll N,x,k=0,ans=1;
	stack<ll> S;
	cin>>N;
	rep(i,N){
		cin>>x;
		k++;
		if(x>=k*2-1){
		}else{
			ans=ans*k%MOD;
			// cout<<ans<<endl;
			k--;
		}
	}
	if(k>0)ans=ans*f(k)%MOD;
	cout<<ans<<endl;
	return 0;
}