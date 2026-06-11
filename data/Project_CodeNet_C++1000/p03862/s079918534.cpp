#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n , m , a[N];
long long ans;

int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1; i <= n; i++)
		scanf("%d" , &a[i]);
	for(int i = 1; i <= n; i++){
		int d = (a[i - 1] + a[i]) - m;
		if(d > 0) a[i] -= d , ans += d;
	}
	printf("%lld" , ans);
	return 0;
}