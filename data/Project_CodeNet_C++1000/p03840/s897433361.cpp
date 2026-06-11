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

lli ai , ao , at , aj , al , as , az, ans;

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> ai >> ao >> at >> aj >> al >> as >> az;
	ans += ao * 2;
	if(ai % 2 + aj % 2 + al % 2 == 0)
		ans += (ai / 2) * 4 + (aj / 2) * 4 + (al / 2) * 4;
	else if(ai % 2 + aj % 2 + al % 2 == 1)
		ans += (ai / 2) * 4 + (aj / 2) * 4 + (al / 2) * 4;
	else if(ai % 2 + aj % 2 + al % 2 == 3)
		ans += (ai / 2) * 4 + (aj / 2) * 4 + (al / 2) * 4 + 6;
	else if(ai == 0 || aj == 0 || al == 0)
		ans += (ai / 2) * 4 + (aj / 2) * 4 + (al / 2) * 4;
	else
		ans += (((ai + aj + al) * 4) / 2) - 2;

	cout << ans / 2;
}