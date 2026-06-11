#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int N;
int a[100010];

int main() {
	cin >> N;
	rep(i, N) cin >> a[i];
	sort(a, a + N, greater<int>());

	int i = 0;
	while (i + 1 < N && a[i + 1] > i + 1) ++i;

	int p = a[i] - i;

	int j = i;
	while (j + 1 < N && a[j + 1] > i) ++j;

	int q = j - i + 1;

	if (p % 2 == 1 && q % 2 == 1) {
		puts("Second");
	} else {
		puts("First");
	}

	return 0;
}