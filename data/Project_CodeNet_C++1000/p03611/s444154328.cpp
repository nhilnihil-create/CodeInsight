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

int lbound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] >= b){
			e = m;
		}
		else{
			s = m;
		}
	}
	if(v[max(s - 1, 0)] >= b) return max(s - 1, 0);
	else if(v[s] >= b) return s;
	else if(v[min(s + 1, l - 1)] >= b) return min(s + 1, l - 1);
	else return v.size();
}

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

long long N;
vector<long long> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());

	long long ans = 0;
	for(long long i=A[0]; i<=A[N-1]; i++){
		int u = ubound(A, i + 1);
		int v = lbound(A, i - 1);
		if(ans < u - v){
			ans = u - v;
		}
	}
	printf("%lld\n", ans);
	return 0;
}