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

typedef unsigned long long LL;

LL Combination(int n, int r){
	if(n < 0 || r < 0 || r > n) return 0;

	if(n - r < r) r = n - r;
	if(r == 0) return (LL)1;
	if(r == 1) return (LL)n;

	int *numerator   = (int*)calloc(r, sizeof(int));
	int *denominator = (int*)calloc(r, sizeof(int));
	if(numerator == NULL || denominator == NULL) return 0;

	for(int i=0; i<r; i++){
		numerator[i] = n - r + 1 + i;
		denominator[i] = i + 1;
	}

	for(int p=2; p<=r; p++){
		int pivot = denominator[p-1];
		if(pivot > 1){
			int offset = (n - r) % p;
			for(int k=p-1; k<r; k+=p){
				numerator[k - offset] /= pivot;
				denominator[k] /= pivot;
			}
		}
	}

	LL res = 1;
	for(int i=0; i<r; i++){
		if(numerator[i]) res *= numerator[i];
	}
	return res;
}

LL N, P;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> P;
	long long odd = 0, even = 0;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		if((a % 2) == 0){
			even++;
		}
		else{
			odd++;
		}
	}

	LL ans = 0;
	if(P == 0){
		for(int i=0; i<=odd; i+=2){
			for(int j=0; j<=even; j++){
				ans += ( Combination(odd, i)*Combination(even, j) );
			}
		}
	}
	else{
		for(int i=1; i<=odd; i+=2){
			for(int j=0; j<=even; j++){
				ans += ( Combination(odd, i)*Combination(even, j) );
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
