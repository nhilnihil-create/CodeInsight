#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

typedef long long ll;

int A[N], dp[N][2], n;
ll sol = 0;

int f(int x, int lst){
	if(!A[x] && lst) return -N;
	if(x == n) return 0;
	if(dp[x][lst] != -1) return dp[x][lst];
	return dp[x][lst] = max((A[x] == 2 && !lst) ? f(x + 1, 0) + 1 : 0, max(f(x + 1, 0), (A[x] > lst ? f(x + 1, 1) + 1 : 0)));
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		if(A[i] > 2){
			sol += (A[i] - 1) / 2;
			A[i] %= 2; 
			if(!A[i])
				A[i] = 2;
		}
		if(A[i] == 2 && (i == 0 || i == n - 1)){
			sol++; A[i] = 0;
		}
	}	
	printf("%lld\n", sol + f(0, 0));
}