#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 500;

int n, A[N], x;

int B(int i){
	return (A[i] > x);
}

bool provjeri(){
	if(B(n - 1) == B(n))
		return B(n - 1);
	if(B(n - 1) == B(n - 2))
		return B(n - 1);
	int l = n - 1, r = n - 1;
	while(l > 0 && B(l) != B(l - 1))
		l--;
	while(r < 2 * n - 2 && B(r) != B(r + 1))
		r++;
	if(l == 0)
		return B(r);
	if(r == 2 * n - 2)
		return B(l);
	if((n - 1) - l < r - (n - 1))
		return B(l);
	return B(r);
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < 2 * n - 1;i++){
		scanf("%d", A + i);
	}
	for(int i = 20;i >= 0;i--){
		x += (1 << i);
		if(!provjeri())
			x -= (1 << i);
	}
	printf("%d\n", x + 1);
}
