#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T> inline T re(){
	T N = 0; char c = getchar(); bool neg = 0;
	for (; c < '0' || c > '9'; c = getchar()) neg |= c == '-';
	for (; c >= '0' && c <= '9'; c = getchar())
		N = (N<<3)+(N<<1) + c - '0';
	return neg ? -N : N;
}

const int mxsz = 1e5 + 3;
int n;
LL a[mxsz], d[mxsz];

inline void CANNOT(){
	puts("NO"); exit(0);
}
int main(){
	n = re<int>();
	for (int i = 1; i <= n; i++) a[i] = re<LL>();
	a[n+1] = a[1];
	LL totdiff = 0, tot = 0, add = 1LL * n * (n+1) / 2;
	for (int i = 1; i <= n; i++){
		totdiff += (d[i] = a[i] - a[i+1]);
		tot += a[i];
	}
	if (tot % add != 0) CANNOT();
	if (totdiff != 0) CANNOT();
	LL m = tot / add;
	LL totx = 0;
	for (int i = 1; i <= n; i++){
		if ((d[i] + m) % n != 0){
			CANNOT();
		}
		LL tmp = (d[i] + m) / n;
		if (tmp < 0) CANNOT();
		totx += tmp;
	}
	if (totx != m) CANNOT();
	cout << "YES\n";
	return 0;
}
