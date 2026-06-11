#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 20;

int a[maxn];

void prnt(vector<int> x)
{
	vector<int> tmp;
	for(auto a : x)
		if(a)
			tmp.pb(a);

	cout << tmp.size() << endl;
	for(auto x : tmp)
		cout << x << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
		cin >> a[i];

	if(m == 1)
	{
		cout << a[0] << endl;
		prnt({a[0] - 1 , 1});
		return 0;
	}

	vector<int> x , y;
	for(int i = 0; i < m; i++)
	{
		if(a[i] & 1)
			x.pb(a[i]);
		else
			y.pb(a[i]);
	}

	if((int)x.size() > 2)
		return cout << "Impossible" << endl , 0;

	if((int)x.size() >= 1)
		y.insert(y.begin() , x[0]);
	if((int)x.size() >= 2)
		y.pb(x[1]);

	for(auto x : y)
		cout << x << " ";
	cout << endl;
	y[0]--;
	y.back()++;
	prnt(y);
}
















