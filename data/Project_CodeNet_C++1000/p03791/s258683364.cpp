#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int bst[100000], n, x[100000], md = 1e9 + 7;

int main(){
	scanf("%d", &n);
	f(i, 0, n)scanf("%d", x + i);
	int first = x[0], b = 1;
	bst[0] = 1;
	f(i, 1, n){
		if (first <= 0)first += 2, ++b;
		bst[i] = b;
		if (x[i] > x[i - 1] + 1)x[i] = x[i - 1] + 2;
		else --first;
	}
	int an = 1;
	for (int i = n - 1; i >= 0; --i){
		int s = i + 1;
		an = (ll)an * (s - bst[i] + 1) % md;
	}
	printf("%d\n", an);
}
