#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son)/2)
#define N 1000005
using namespace std;

typedef long long ll;

ll n, A, B, bas, son, h[N];

bool dene(ll x){
	ll kal = x;
	for(int i = 1; i <= n; i++){
		ll bas = 0, son = kal + 1;
		while(bas < son)
			if(orta*A + (x - orta)*B >= h[i])
				son = orta;
			else
				bas = orta + 1;
		if(orta > kal)
			return 0;
		kal -= orta;
	}
	return 1;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("amk.txt", "w", stdout);
	scanf("%lld %lld %lld",&n ,&A ,&B);
	for(int i = 1; i <= n; i++){
		scanf("%lld",h + i);
		son = max(son, h[i]/B + 2);
	}
	while(bas < son)
		if(dene(orta))
			son = orta;
		else
			bas = orta + 1;
	printf("%lld\n", orta);
	return 0;
}
