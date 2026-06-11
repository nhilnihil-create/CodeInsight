#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

ll ones(int x){
	ll ret=0;
	for(;x--;) ret=10*ret+1;
	return ret;
}

ll get_kth(int k){
	--k;
	ll ret = 0;
	for(int dep=1; dep<=9; ++dep){
		if(!k && dep>1){
			break;
		}
		if(dep>1) --k;
		for(int i=(dep==1); i<=9; ++i){
			if(ones(10-dep) <= k){
				k -= ones(10-dep);
			} else {
				ret=10*ret + i;
				break;
			}
		}
	}
	return ret;
}

bool Test(ll x){
	printf("? %lld\n", x);
	fflush(stdout);
	char buf[5]; scanf("%s", buf);
	return buf[0] == 'Y';
}

int main()
{
	if(Test(1e9)){
		ll A=1;
		while(true){
			if(Test(10*A-1)) break;
			A *= 10;
		}
		printf("! %lld\n", A);
	} else {
		ll l=1, r=1e9;
		while(l < r){
			ll mid=(l+r)/2;
			ll q = get_kth(mid);
			while(q <= ll(1e10)) q*=10;
			if(Test(q)) r=mid;
			else l=mid+1;
		}
		ll ap = get_kth(l);
		ll co = 1;
		while(true){
			co *= 10;
			if(!Test((ap-1)*co)) break;
		}
		ap *= co/10;
		printf("! %lld\n", ap);
	}
	return 0;
}
