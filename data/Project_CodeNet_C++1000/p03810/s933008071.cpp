#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int x[100000];

void win(bool f) { printf("%s\n", f ? "First" : "Second"), exit(0); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(){
	int n;
	scanf("%d",&n);
	ll s = 0;
	f(i, 0, n){
		scanf("%d", x + i);
		s += x[i] - 1;
	}
	bool p = false;
	if (n & 1){
		while (!(s & 1)){
			int od = 0;
			bool on = false;
			f(i, 0, n) { if (x[i] & 1)++od; if (x[i] == 1) { on = true; break; } }
			if (od != 1 || on)break;
			p = !p;
			int r = x[0] & ~1;
			f(i, 0, n){
				if (x[i] & 1)x[i] &= ~1;
				r = gcd(r, x[i]);
			}
			s = 0;
			f(i, 0, n)x[i] /= r, s += x[i] - 1;
		}
	}
	win(s & 1 ^ p);
}
