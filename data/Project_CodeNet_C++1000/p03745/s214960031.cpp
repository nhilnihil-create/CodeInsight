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

long long N;
vector<long long> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	long long ans = 1;
	long long diff = 0;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
		if(i > 0){
			long long w = A[i] - A[i-1];
			if(w == 0){
				continue;
			}
			else if(w > 0){
				if(diff == 0){
					diff = w;
				}
				else if(diff < 0){
					ans++;
					diff = 0;
				}
			}
			else if(w < 0){
				if(diff == 0){
					diff = w;
				}
				else if(diff > 0){
					ans++;
					diff = 0;
				}
			}
			else{
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}