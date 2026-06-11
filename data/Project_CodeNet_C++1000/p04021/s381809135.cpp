#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

int A[N], n, x, B[N];
map < int , int > rev;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		B[i] = A[i];
	}
	sort(B, B + n);
	for(int i = 0;i < n;i++){
		rev[B[i]] = i;
	}
	for(int i = 0;i < n;i++){
		x += (i - rev[A[i]] + N) % 2;
	}
	printf("%d\n", x / 2);
	return 0;
}