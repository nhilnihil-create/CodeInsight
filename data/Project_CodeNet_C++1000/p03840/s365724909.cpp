#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son)/2)
#define N 1000005
using namespace std;

typedef long long ll;

ll i, o, t, j, l, s, z, ans, bas, son;

ll bul(ll kac){
	ll ans = 0;
	ans += o;
	ans += kac*3;
	ans += (i - kac)/2*2;
	ans += (j - kac)/2*2;
	ans += (l - kac)/2*2;
	return ans;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld %lld %lld %lld %lld %lld %lld",&i ,&o ,&t ,&j ,&l ,&s ,&z);
	son = min(i, min(l, j));
	while(bas < son){
		if(bul(orta) < bul(orta + 1))
			bas = orta + 1;
		else
			son = orta;
	}
	printf("%lld\n", bul(orta));
	return 0;
}