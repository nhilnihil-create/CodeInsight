#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;

static LL P = 1000000007;

int isPrime(LL p){
	if(p<=1) return 0;
	if(p==2 || p==3 || p==5 || p==7) return 1;
	if(p==4 || p==6 || p==8 || p==9) return 0;

	LL i;
	int ret = 1;
	for(i=2; i*i<=p; i++){
		if(p%i==0 && i!=p){
			ret = 0;
			break;
		}
	}
	return ret;
}

void factorize(long long N, map<long long, int> &mp){
	if(N == 1){
		printf("1 is not prime.\n");
		return;
	}
	if(isPrime(N)){
		mp[N] += 1;
		return;
	}

	long long i = 2, n = N;
	for(i = 2; n != 1 && i < (N/2) + 1; i++){
		if((n % i)==0){
			if(isPrime(i)){
				int e = 0;
				long long u = n;
				while((u % i)==0){
					e++;
					u = u / i;
					n = u;
				}
				mp[i] += e;
				if(isPrime(n)){
					mp[n] += 1;
					break;
				}
			}
		}
	}
	return;
}


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N;
	map<long long, int> mp;

	cin >> N;

	for(int i = 2; i <=N; i++){
		factorize(i, mp);
	}

	LL ans = 1;
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		long long p = itr->first;
		int v = itr->second;
		if(v == 0) continue;
		ans *= ((v + 1) % P);
		ans = ans % P;
	}
	printf("%lld\n", ans);
	return 0;
}