#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int n, m;
int a[MAXN];

void read()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> a[i];
}

void solve()
{
	vector<int> odd, even;
	for(int i = 0; i < m; i++)
		if(a[i] % 2 == 0) even.push_back(a[i]);
		else odd.push_back(a[i]);

	if(odd.size() > 2)
	{
		cout << "Impossible" << endl;
		return;
	}

	if(m == 1 && a[0] == 1)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 1 << endl;
		return;
	}

	if(m == 1)
	{
		cout << a[0] << endl;
		cout << 2 << endl;
		cout << a[0] - 1 << " " << 1 << endl;
		return;
	}

	while(odd.size() < 2)
	{
		odd.push_back(even.back());
		even.pop_back();
	}

	vector<int> li1, li2;
	if(!odd.empty()) 
	{
		li1.push_back(odd.back());
		if(odd.back() != 1) li2.push_back(odd.back() - 1);
		odd.pop_back();
	}

	for(int x: even)
	{
		li1.push_back(x);
		li2.push_back(x);
	}
	
	if(!odd.empty()) 
	{
		li1.push_back(odd.back());
		li2.push_back(odd.back() + 1);
		odd.pop_back();
	}

	for(int x: li1) cout << x << " "; 
	cout << endl;
	cout << li2.size() << endl;
	for(int x: li2) cout << x << " "; 
	cout << endl;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

