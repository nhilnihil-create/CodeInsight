#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;

ll po[20];char opt[10];
inline bool Query(ll x){
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s", opt);
	return opt[0] == 'Y';
}

int main(){
	po[0] = 1;
	for(int i = 1;i <= 18;++i)po[i] = 10LL * po[i - 1];
	bool flag = 1;
	ll L = 0;
	for(int i = 1;i <= 9;++i){
		if(!Query(po[i])){
			flag = 0;
			if(!L)L = po[i - 1];
		}
	}
	if(flag){
		int l = 0, r = 9, mid, pos = 9;
		while(l <= r){
			mid = l + r >> 1;
			if(Query(2LL * po[mid]))pos = min(pos, mid), r = mid - 1;
			else l = mid + 1;
		}
		printf("! %lld\n", po[pos]);
	}
	else{
		ll r = L * 10 - 1, l = L + 1, mid, ans = r;
		while(l <= r){
			mid = l + r >> 1;
			if(Query(10LL * mid))ans = min(ans, mid), r = mid - 1;
			else l = mid + 1;
		}
		printf("! %lld\n", ans);
	}
	fflush(stdout);
	return 0;
}
