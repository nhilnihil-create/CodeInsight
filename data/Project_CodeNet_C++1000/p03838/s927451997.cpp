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

long long x, y;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> x >> y;

	long long ans = 0;
	if(x == y){
		ans = 0;
		printf("%lld\n", ans);
		return 0;
	}
	if(x == (-1)*y){
		ans = 1;
		printf("%lld\n", ans);
		return 0;
	}
	if(x == 0){
		ans = abs(y);
		if(y < 0){
			ans++;
		}
		printf("%lld\n", ans);
		return 0;
	}

	if(x > 0){
		if(y >= x){
			ans = abs(x - y);
			printf("%lld\n", ans);
			return 0;
		}
		else{
			ans = abs(abs(x) - abs(y)) + 1;
			if(y > 0){
				ans++;
			}
			printf("%lld\n", ans);
			return 0;
		}
	}
	else if(x < 0){
		if(y <= x){
			ans = abs(abs(x) - abs(y)) + 2;
			printf("%lld\n", ans);
			return 0;
		}
		else{
			if(y < (-1)*x){
				ans = abs(abs(x) - abs(y));
				if(y > 0){
					ans++;
				}
				printf("%lld\n", ans);
				return 0;
			}
			else{
				ans = abs(abs(x) - abs(y)) + 1;
				printf("%lld\n", ans);
				return 0;
			}
		}
	}
	return 0;
}

