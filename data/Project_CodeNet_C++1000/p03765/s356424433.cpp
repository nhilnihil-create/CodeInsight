#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const long long INF = 1e18;
const int mod = 1e9 + 7;//1e9 + 7;//786433;//998244353;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int psum[100005], psum2[100005];
string a, b;

signed main()
{
	Fastio();
	cin >> a >> b;
	for(int i = 0; i < (int)a.length(); i++)
	{
		psum[i + 1] = psum[i] + (a[i] == 'A');	
	}
	for(int i = 0; i < (int)b.length(); i++)
	{
		psum2[i + 1] = psum2[i] + (b[i] == 'A');
	}
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int l, r, l2, r2;
		cin >> l >> r >> l2 >> r2;
		int temp = psum[r] - psum[l - 1], temp2 = psum2[r2] - psum2[l2 - 1];
		if((temp + 2 * (r - l + 1 - temp) - temp2 - 2 * (r2 - l2 + 1 - temp2)) % 3 == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}