#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define befv(V) ((V)[(sz(V)-2)])
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int H, W, T;

int main() {
	cin >> H >> W >> T;

	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++) {
			int c = (!!((i-j+INF)%(T<<1) < T)) << 1 | (!!((i+j)%(T<<1) < T));
			putchar("RGBY"[c]);
		}
		puts("");
	}
	return 0;
}