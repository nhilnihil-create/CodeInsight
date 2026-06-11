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

int n, ar[N];

bool check(int x) {
	int t[N];
	bool fl = false;
	for(int i = 1; i <= 2 * n - 1; i++)
		t[i] = ar[i] >= x;
	for(int i = 1; i < 2 * n - 1; i++)
		if(t[i] == t[i + 1])
			fl = true;
	if(!fl) {
		if(n % 2 == 1)
			return t[n] == 1;
		else
			return t[n] == 0;
	}
	int ind1 = n, ind2 = n;
	while(1) {
		if(t[ind1] == t[ind1 - 1])
			return t[ind1];
		else if(t[ind2] == t[ind2 + 1])
			return t[ind2];
		ind1--;
		ind2++;
	}
}

int bs(int x, int y) {
	if(x == y)
		return x;
	if(x + 1 == y) {
		if(check(y))
			return y;
		else
			return x;
	}
	if(check(mid))
		bs(mid, y);
	else
		bs(x, mid - 1);
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(int i = 1; i <= 2 * n - 1; i++)
		cin >> ar[i];
	if(n == 1)
		cout << 1;
	else
		cout << bs(1, 2 * n - 1);
}