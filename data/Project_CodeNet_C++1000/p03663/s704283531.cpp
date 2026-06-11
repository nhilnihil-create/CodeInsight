#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

char in[5];
int inf = 1e9;

bool q(ll n){
	printf("? %lld\n", n);
	fflush(stdout);
	scanf("%s", in);
	return in[0] == 'Y';
}

inline string S(ll x){
	string s;
	while (x)s += x % 10 + '0', x /= 10;
	reverse(s.begin(), s.end());
	return s;
}

int N;
string SS;
/*bool q(ll n){
	string s = S(n);
	printf("? %lld\n", n);
	return n <= N && s <= SS || n > N && s > SS;
}*/

void win(int an){
	printf("! %d\n", an);
	fflush(stdout);
	exit(0);
}

inline int dc(ll x){
	int an = 0;
	while (x)++an, x /= 10;
	return an;
}

inline ll fl(ll x){
	int d = dc(x);
	f(i, d, 15)x *= 10;
	return x;
}

inline ll one(int x){
	ll an = 1;
	f(i, 0, x)an *= 10;
	return an;
}

int bs(ll x, bool z){
	int l = 1, r = 9;
	if (z)l = 0;
	while (r > l){
		int m = l + r + 1 >> 1;
		ll t = x * 10 + m;
		if (q(t))l = m;
		else r = m - 1;
	}
	if (l < 9)return l;
	ll t = x * 10 + 9;
	ll tt = fl(t);
	if (q(tt)){
		int l = 0, r = 9;
		if (!z)l = 1;
		ll tttt = one(dc(x) + 1);
		if (q(tttt))return 9;
		while (r > l){
			int m = l + r + 1 >> 1;
			ll ttt = x * 10 + m;
			if (q(ttt * 10 - 1))r = m - 1;
			else l = m;
		}
		win(x * 10 + l);
	}
	t = t * 10 - 1;
	if (q(t))return 9;
	win(x * 10 + 9);
	return 0;
}

int main(){
	/*scanf("%d", &N);
	SS = S(N);*/
	
	ll an = 0;
	if (q(inf)){
		int l = 0, r = 9;
		while (r > l){
			int m = l + r >> 1;
			if (q(one(m) << 1))r = m;
			else l = m + 1;
		}
		win(one(l));
	}
	while (true)an = an * 10 + bs(an, an);
}