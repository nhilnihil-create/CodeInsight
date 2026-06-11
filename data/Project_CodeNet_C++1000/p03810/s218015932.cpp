#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 100010;

int A[N];
bool ans;

int gcd(int x, int y){
	return !y ? x : gcd(y, x % y);
}

void quit(){
	puts(ans ? "First" : "Second");
	exit(0);
}

int main(){
	int n;
	scanf("%d", &n);

	long long sum = 0;
	For(i, 1, n){
		scanf("%d", &A[i]);
		sum += A[i];
	}
	ans = (sum - n) & 1;

	while((sum - n) % 2 == 0){
		int pos = 0;
		For(i, 1, n) if(A[i] & 1){
			if(pos) quit();
			pos = i;
		}

		if(A[pos] == 1) quit();

		A[pos]--;
		int g = A[pos];
		For(i, 1, n) g = gcd(g, A[i]);
		if((sum - 1) / g % 2 == (sum - 1) % 2) quit();

		sum = 0;
		For(i, 1, n) A[i] /= g, sum += A[i];
		ans ^= 1;

	}
	quit();

	return 0;
}