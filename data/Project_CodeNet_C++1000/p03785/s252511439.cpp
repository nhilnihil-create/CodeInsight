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

long long N, C ,K;
vector<long long> T;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> C >> K;
	for(int i=0; i<N; i++){
		long long t;
		cin >> t;
		T.push_back(t);
	}
	sort(T.begin(), T.end());

	long long ans = 0;
	long long s = T[0];
	int spos = 0;
	auto its = T.begin();
	while(its != T.end()){
		long long e = s + K;
		int epos = ubound(T, e);
		auto ite = upper_bound(T.begin() + spos, T.end(), e);
		ans++;
		if(epos - spos <= C){
			spos = epos;
			s = T[spos];
			its = ite;
		}
		else{
			spos = spos + C ;
			s = T[spos];
			its = T.begin() + spos;
		}
	}
	printf("%lld\n", ans);
	return 0;
}