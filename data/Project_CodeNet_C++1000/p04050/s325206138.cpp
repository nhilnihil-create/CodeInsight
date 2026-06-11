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
const LL INF = 1000 * 1000 *1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1010;
int A[MAX];

int main()
{
	//freopen("in.txt","r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	scanf("%d%d", &n, &m);
	FOR (i, 0, m)
	{
		scanf("%d", &A[i]);
	}

	FOR (i, 1, m - 1)
	{
		if (A[i] % 2 == 1)
		{
			swap(A[0], A[m-1]);
			swap(A[0], A[i]);
		}
	}

	FOR (i, 1, m-1)
	{
		if (A[i] & 1)
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}

	FOR (i, 0, m)
	{
		cout<<A[i]<<' ';
	}
	cout<<endl;

	if (m == 1)
	{
		if (A[0] == 1) cout<<"1\n1"<<endl;
		else cout<<2<<endl<<A[0] - 1<<' '<<1<<endl;
		return 0;
	}

	if (A[0] == 1) m--;
	cout<<m<<endl;
	if (A[0] != 1) cout<<A[0] - 1;
	else m++;
	FOR (i, 1, m - 1)
	{
		cout<<' '<<A[i];
	}

	cout<<' '<<A[m-1]+1<<endl;


}
