#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
int n, m;
vector<int> a;
int main () {
	cin >> n >> m;
	a.resize(m);
	for(int i = 0; i < m; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if(m <= 2) {
		for(int i = 0; i < m; i++) {
			if(i > 0) cout << " ";
			cout << a[i];
		}
		cout << "\n";
		if(a[0] == 1) {
			cout << 1 << "\n" << n <<"\n";
		} else if(m == 1) {
			cout << "2\n" << n-1 << " 1\n";
		}
		else {
			cout << 2 << "\n" << a[0] + 1 << " " << a[1] - 1 << "\n";
		}
		return 0;
	}
	int cnt = 0;
	for(int &x: a) cnt += x % 2;
	if(cnt > 2) {
		cout << "Impossible\n";
		return 0;
	}
	for(int i = 0; i < m; i++) {
		if(a[i] % 2) {
			swap(a[0], a[i]);
			break;
		}
	}
	for(int i = 1; i < m; i++) {
		if(a[i] % 2) {
			swap(a[m-1], a[i]);
			break;
		}
	}
	for(int i = 0; i < m; i++) {
		if(i > 0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
	if(a[0] == 1) {
		a.back()+=1;
		a.erase(a.begin());
	}else {
		a[0] -= 1;
		a.back() += 1;
	}
	cout << a.size() << "\n";
	for(int i = 0; i < a.size(); i++) {
		if(i > 0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
 	return 0;
}

