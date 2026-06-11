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

const int MAX = 100005;
const int P = 1000000007; //shuoud be prime

long long fac[MAX], finv[MAX], inv[MAX];

void COMBinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % P;
        inv[i] = P - inv[P%i] * (P / i) % P;
        finv[i] = finv[i - 1] * inv[i] % P;
    }
}

long long N, M;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	COMBinit();

	if(abs(N - M) > 1){
		printf("0\n");
		return 0;
	}

	long long ans = fac[N];
	ans *= fac[M];
	if(N == M){
		ans *= 2;
	}
	ans = ans % P;
	if(ans < 0) ans += P;

	printf("%lld\n", ans);
	return 0;
}