#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define DEBUG(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = INT_MAX;
const LL INF = LLONG_MAX;

template <typename T> inline T read ()
{
	T sum = 0, fl = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
	return sum * fl;
}

const int maxn = 1e5 + 5;

int N;
int A[maxn];

inline void solve ()
{
	sort (A + 1, A + N + 1, greater <int> ());
	
	for (int i = 1; i <= N; ++i) if (i + 1 > A[i + 1])
	{
		int d1 = A[i] - i, d2 = 0;
		for (int j = i + 1; j <= N; ++j) if (A[j] == i) ++d2;

		d1 += 2; d2 += 2;
		if ((d1 & 1) || (d2 & 1)) printf ("First");
		else printf ("Second");

		break;
	}
}

inline void input ()
{
	N = read<int>();
	for (int i = 1; i <= N; ++i) A[i] = read<int>();
}

int main ()
{


	input ();
    solve ();

    return 0;
}
