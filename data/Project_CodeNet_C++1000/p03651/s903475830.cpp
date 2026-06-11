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
long long INF = (1LL<<62);

typedef long long LL;

long long N, K;
vector<long long> A;

int ubound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] <= b){
			s = m;
		}
		else{
			e = m;
		}
	}
	if(v[max(s - 1, 0)] > b) return max(s - 1, 0);
	else if(v[s] > b) return s;
	else if(v[min(s + 1, l - 1)] > b) return min(s + 1, l - 1);
	else return v.size();
}

LL GCD(LL x, LL y){
        LL r=0;
	if( x<y ) swap(x, y);
        r = x % y;
        while(r!=0){
                x = y;
                y = r;
                r = x % y;
        }
        return y;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	if(N == 1){
		if(K == A[0]){
			printf("POSSIBLE\n");
		}
		else{
			printf("IMPOSSIBLE\n");
		}
		return 0;
	}

	if(K > A[A.size()-1]){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	if(A[0] == 1){
		printf("POSSIBLE\n");
		return 0;
	}
	int pos = ubound(A, K);
	if(pos > 0 && A[pos-1] == K){
		printf("POSSIBLE\n");
		return 0;
	}

	LL d = GCD(A[0], A[1]);
	for(int i=2; i<A.size(); i++){
		d = GCD(d, A[i]);
	}
	if((K % d) == 0){
		printf("POSSIBLE\n");
	}
	else{
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
