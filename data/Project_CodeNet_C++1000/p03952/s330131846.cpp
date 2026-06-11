#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll MAXN = 1e6 + 10;
const ll N = 4000 + 10;
const ll MN = 200 + 10;
const ll mod = 1e6;

ll a[MAXN * 2];

int main()
{
	faster();
	ll n , x;
	cin >> n >> x;
	ll cnt = 1;
	if(x != 1 && x != 2 * n - 1)
	{
		cout << "Yes\n";
		set <int> s;
		a[n - 1] = x;
		a[n - 2] = x - 1;
		a[n] = x + 1;
		for (int i = 1; i <= 2 * n - 1; i++)
		{
			if(i < x - 1 || i > x + 1)
				s.insert(i);
		}
		for (int i = 0; i < 2 * n - 1; i++)
		{
			if(a[i] == 0)
			{
				a[i] = *s.begin();
				s.erase(s.find(a[i]));
			}
			cout << a[i] << endl;
		}
	}
	else
		cout << "No\n";
}