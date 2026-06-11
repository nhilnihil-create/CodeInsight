#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <random>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

long long int powmod(long long int a, long long int k, long long int m){
    if(a==0) return 0;
    long long int ap=a, ans=1;
    while(k>0){
        if(k%2==1){
            ans*=ap;
			ans%=m;
        }
        ap=ap*ap;
		ap%=m;
        k/=2;
    }
    return ans;
}

ll inv(ll a, ll p){
	return powmod(a, p-2, p);
}

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m=s.size();

	ll f[5001];
	f[0]=1;
	for(ll i=1; i<=n; i++){
		f[i]=f[i-1]*i%MOD;
	}
	ll invf[5001];
	invf[n]=inv(f[n], MOD);
	for(ll i=n-1; i>=0; i--){
		invf[i]=invf[i+1]*(i+1)%MOD;
	}
	ll p2[5001];
	p2[0]=1;
	for(int i=1; i<=n; i++){
		p2[i]=p2[i-1]*2%MOD;
	}

	ll dp[5001]={};
	dp[0]=1;
	for(int i=0; i<n; i++){
		dp[i+1]+=dp[i];
		dp[i+1]%=MOD;
		for(int j=1; i+2*j<=n; j++){
			ll x;
			if(j==1) x=2;
			else x=(f[2*j-2]*invf[j-1]%MOD*invf[j-1]%MOD-f[2*j-2]*invf[j]%MOD*invf[j-2]%MOD+MOD)*p2[j]%MOD;
			dp[i+2*j]+=(dp[i]*x);
			dp[i+2*j]%=MOD;
		}
	}
	ll ans=0;
	for(int i=0; 2*i+m<=n; i++){
		ll x;
		if(i==0) x=1;
		else x=(f[2*i+m-1]*invf[i+m-1]%MOD*invf[i]%MOD-f[2*i+m-1]*invf[i-1]%MOD*invf[i+m]%MOD+MOD)*p2[i]%MOD;
      ans+=(dp[n-2*i-m]*x);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}