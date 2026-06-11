#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, a[maxn], arrl, lazy, pos[maxn], val[maxn];
pair<int, int> arr[maxn];
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i && a[i] == a[i - 1])
			arr[arrl - 1].ss++;
		else
			arr[arrl++] = mp(a[i], 1);
	}
	/*for (int i = 0; i < arrl; i++)
		cerr << '@' << arr[i].ff << ' ' << arr[i].ss << endl;
	cerr << "__________________" << endl;*/

	for (int i = 1; i < arrl; i++)
		pos[i] = pos[i - 1] + arr[i - 1].ss;
	int head;
	if (arrl >= 2)
		head = (arr[arrl - 1].ff - arr[arrl - 2].ff + 1) % 2;
	else
		head = (arr[arrl - 1].ff + 1) % 2;
	for (int i = arrl - 2; i >= 0; i--)
	{
		int now = (arr[i].ss + 1) % 2, delta;
		if (i)
			delta = (arr[i].ff - arr[i - 1].ff - 1);
		else
			delta = arr[i].ff - 1;
		//cerr << '#' << i << ' ' << head << ' ' << now << endl;
		if (now == 0 && head == 0)
			lazy++;
		else if (now == 1 && head == 0)
		{
			lazy++;
			//cerr << "LAZY " << lazy << ':' << pos[i + 1] << endl;
			dq.pf(pos[i + 1] - lazy);
		}
		else if (now == 0 && head == 1)
		{
			lazy++;
			dq.pf(pos[i + 1] - lazy + 1);
		}
		else
			lazy++;
		lazy += delta;

		while (!dq.empty() && dq.back() + lazy >= n)
			dq.popb();

		head = 0;
		if (i)
		{
			head += arr[i].ff - arr[i - 1].ff - 1;
			head %= 2;
		}
		else
		{
			head += arr[i].ff - 1;
			head %= 2;
		}
	}
	//cerr << "END " << head << ' ' << dq.size() << endl;
	for (int i = 0; i < dq.size(); i++)
	{
		dq[i] += lazy;
		//cerr << '$' << dq[i];
	}
	//cerr << endl;
	val[0] = head;
	int pos = 0;
	for (int i = 1; i < n; i++)
	{
		if (pos < dq.size() && i == dq[pos])
		{
			pos++;
			val[i] = val[i - 1];
		}
		else
			val[i] = 1 - val[i - 1];
	}
	/*for (int i = 0; i < n; i++)
		cerr << '_' << val[i];
	cerr << endl;*/
	cout << (val[n - 1] ? "First" : "Second") << endl;
}

