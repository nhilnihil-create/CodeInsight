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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL A, B, C;
	LL a, b, c;
	cin >> A >> B >> C;

	a = A, b = B, c =C;

	LL ans = 0;
	while(true){
		if((a % 2) !=0 || (b % 2) !=0 || (c % 2) != 0){
			break;
		}
		if(a == b && b == c){
			printf("-1\n");
			return 0;
		}

		ans++;
		LL u = a, v = b, w = c;
		a = v/2 + w/2;
		b = w/2 + u/2;
		c = u/2 + v/2;

		if(a == A && b == B && c == C){
			printf("-1\n");
			return 0;
		}
		if(a == A && b == C && c == B){
			printf("-1\n");
			return 0;
		}
		if(a == B && b == A && c == C){
			printf("-1\n");
			return 0;
		}
		if(a == B && b == C && c == A){
			printf("-1\n");
			return 0;
		}
		if(a == C && b == B && c == A){
			printf("-1\n");
			return 0;
		}
		if(a == C && b == A && c == B){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
