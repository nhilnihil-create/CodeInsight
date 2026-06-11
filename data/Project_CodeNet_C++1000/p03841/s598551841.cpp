#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int n, i, j;
	cin >> n;
	vi a(n*n);
	vector<pii> x(n);
	for (i = 0; i < n; i++) {
		cin >> x[i].first;
		x[i].first--;
		x[i].second = i + 1;
		if (a[x[i].first] != 0) {
			cout << "No" << endl;
			return 0;
		}
		else {
			a[x[i].first] = i + 1;
		}
	}
	sort(x.begin(), x.end());

	int stock = 0;
	j = 0;
	for (i = 0; i < n; i++) {
		int m = x[i].second;
		int cnt = m - 1;
		while (cnt > 0) {
			if (a[j] == 0) {
				a[j] = m;
				cnt--;
			}
			j++;
		}
	}
	for (i = 0; i < n; i++) {
		int m = x[i].second;
		int cnt = n - m;
		while (cnt > 0) {
			if (a[j] == 0) {
				a[j] = m;
				cnt--;
			}
			j++;
		}
	}
	vi num(n + 1);
	j = 0;
	for (i = 0; i < n*n; i++) {
		num[a[i]]++;
		if (x[j].first == i) {
			if (num[a[i]] != a[i]) {
				cout << "No" << endl;
				return 0;
			}
			j++;
		}
	}
	cout << "Yes" << endl;
	for (i = 0; i < n*n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;


}