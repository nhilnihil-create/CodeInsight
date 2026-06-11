#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);

int n, m, A[N], a[N], b[N];

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m;
	int odd = 0;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		if(A[i] % 2 == 1)
			odd++;
	}
	if(m == 1) {
		if(A[1] == 1) {
			cout << A[1] << endl;
			cout << 1 << endl;
			cout << A[1] << endl;
			return 0;
		}
		cout << A[1] << endl;
		cout << 2 << endl;
		cout << A[1] - 1 << spc << 1;
		return 0;
	}
	if(odd > 2) {
		cout << "Impossible";
		return 0;
	}

	bool fl = false;
	for(int i = 1; i <= m; i++) {
		if(!fl && A[i] % 2 == 1) {
			swap(A[i], A[1]);
			fl = true;
		}
		if(fl && A[i] % 2 == 1)
			swap(A[i], A[m]);
	}

	for(int i = 1; i <= m; i++)
		a[i] = A[i];
	if(a[1] < a[m])
		swap(a[1], a[m]);

	b[1] = a[1] - 1;
	b[m] = a[m] + 1; 
	for(int i = 2; i <= m - 1; i++)
		b[i] = a[i];
	for(int i = 1; i <= m; i++)
		cout << a[i] << spc;
	if(b[1] == 0) {
		cout << endl << m - 1 << endl;
		for(int i = 2; i <= m; i++)
			cout << b[i] << spc;
		return 0;
	}
	cout << endl << m << endl;
	for(int i = 1; i <= m; i++)
		cout << b[i] << spc;
}