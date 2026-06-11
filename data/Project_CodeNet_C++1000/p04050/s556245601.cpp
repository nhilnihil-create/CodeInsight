// :)
// "Khodaya, be man "Tagwaye setiz" biamooz ta
//  dar anbuh masuliat nalaghzam ..." -Shariati
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define F first
#define S second
#define MP make_pair

const int MAX = 1e5+9;
const ll MOD = 1e9+7;

vector <int> e, o;

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x % 2)
			o.push_back(x);
		else
			e.push_back(x);
	}
	vector <int> ans;
	if (n % 2) {
		if (o.size() > 1)
			return cout << "Impossible\n", 0;
		cout << o[0] << " ";
		for (auto x : e)
			cout << x << " ";
		cout << "\n";
		if (o[0]-1)
			cout << m+1 << "\n" << o[0]-1 << " ";
		else
			cout << m << "\n";
		for (auto x : e)
			cout << x << " "; cout << 1 ;
		cout << "\n";
	} else {
		if (o.size() > 2)
			return cout << "Impossible\n", 0;
		if (o.size()) {
			cout << o[0] << " ";
			for (auto x : e)
				cout << x << " ";
			cout << o[1] << "\n";
			if (o[1]-1)
				cout << m << "\n";
			else
				cout << m-1 << "\n";
			cout << o[0]+1 << " ";
			for (auto x : e)
				cout << x << " ";
			if (o[1]-1)
				cout << o[1]-1 << " ";
			cout << "\n";
		} else {
			for (auto x : e)
				cout << x << " ";
			cout << "\n";
			cout << m + ((m == 1) ? 1 : 0) << "\n";
			cout << e[0]-1 << " ";
			if (m-1) {
				for (int i = 1; i < e.size()-1; i++)
					cout << e[i] << " ";
				cout << e[e.size()-1]+1 << " ";
			} else
				cout << 1 ;
			cout << "\n";
		}
	}
}