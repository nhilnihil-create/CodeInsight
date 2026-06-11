#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> V;
ll n,l,t,cnt;

ll f(ll k)
{
	ll i, ret = 0;
	
	for(i=0;i<n;i++){
		if(V[i] == k) ret += t;
		else if(V[i] < k) ret += t + (k - V[i] - 1) / l + 1;
		else ret += t - (V[i] - k) / l;
	}
	
	return ret;
}

int main()
{
	ll i,a,b,s,e,mid,k,x;
	
	scanf("%lld%lld%lld",&n,&l,&t);
	
	for(i=0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		if(b == 1) V.push_back(a + t);
		else V.push_back(a - t);
	}
	
	sort(V.begin(), V.end());
	
	s = -l*t, e = n + l*t;
	
	for(;s<=e;){
		mid = s+e >> 1;
		
		if(f(mid) <= n*t) s = mid+1;
		else e = mid-1;
	}
	
	x = (n*t - f(s-1));
	k = ((s-1) % l + l) % l;
	
	for(i=0;i<n;i++){
		V[i] = (V[i] % l + l) % l;
	}
	
	sort(V.begin(), V.end());
	
	for(i=0;i<n;i++){
		if(V[i] == k) break;
	}
	
	for(k=0;k<n;k++){
		printf("%lld\n",V[(i+k+x)%n]);
	}
	
	return 0;
}