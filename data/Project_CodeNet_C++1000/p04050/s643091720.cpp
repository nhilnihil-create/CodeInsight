#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
#include<set>
#include<stack>
#include<queue>
#include<fstream>
#include<iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include<cmath>
#include<list>
#include <sstream>
#include<unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 + 47;
int A[MAX];
int B[MAX];
int sz;
vector<int> odd;
vector<int> even;

void imp()
{
	cout << "Impossible" << endl;
	exit(0);
}

void print(int A[], int n)
{
	FOR(i, 0, n) cout << A[i] << " ";
	cout << endl;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m) cin >> A[i];
	if (m == 1 && A[0] == 1)
	{
		print(A, 1);
		cout << 1 << endl;
		print(A, 1);
		return 0;
	}

	FOR(i, 0, m)
	{
		if (A[i] & 1)
		{
			odd.push_back(A[i]);
			continue;
		}

		even.push_back(A[i]);
	}

	if (SZ(odd) > 2) imp();
	if (SZ(odd))
	{
		A[sz++] = odd.back();
		odd.pop_back();
	}

	FOR(i, 0, SZ(even)) A[sz++] = even[i];

	if (SZ(odd)) A[sz++] = odd[0];
	print(A, sz);

	if (m == 1)
	{
		m = 2;
		A[0]--;
		A[1] = 1;
	}
	else
	{
		A[0]++;
		if (A[m - 1] == 1)
		{
			m--;
		}
		else
		{
			A[m - 1]--;
		}
	}


	cout << m << endl;
	print(A, m);
}
