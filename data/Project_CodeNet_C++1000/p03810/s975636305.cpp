#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 100100;

int A[MAX];

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

string f = "First";
string s = "Second";

void F()
{
	cout<<f<<endl;
	exit(0);
}

void S()
{
	cout<<s<<endl;
	exit(0);
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		scanf("%d", &A[i]);
	}

	while(true)
	{
		int p = 0;
		int np = 0;
		int ind = -1;
		FOR (i, 0, n)
		{
			if (A[i] % 2 == 0) p++;
			else np++, ind = i;
		}

		if (p % 2 == 1) F();

		if (np == 1)
		{
			if (A[ind] == 1) S();

			A[ind]--;
			int g = 0;
			FOR (i, 0, n)
			{
				g = gcd(g, A[i]);
			}

			FOR (i, 0, n)
			{
				A[i] /= g;
			}

			swap(f, s);

			continue;
		}

		S();
	}

}
