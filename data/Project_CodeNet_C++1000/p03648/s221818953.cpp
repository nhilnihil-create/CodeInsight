#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pr pair<int, int>
#define x first
#define y second
using namespace std;

template<typename T>
void read(T& n){
	char ch; int sign = 1;
	while (!isdigit(ch = getchar())) if (ch == '-') sign = -1;
	n = ch - '0';
	while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
	n *= sign;
}
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 122;
ll k, a[N];

int main(){
	read(k); int n = 50;
	rep(i, 0, n - 1) a[i] = k / n + i;
	k %= n; int pos = 0;
	while(k--){
		a[pos] += n;
		rep(i, 0, n - 1) if (i != pos) a[i]--;
		pos++;
	}
	printf("%d\n", n);
	rep(i, 0, n - 1) printf("%lld%c", a[i], " \n"[i == n - 1]);
	return 0;
}