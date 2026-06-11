//struct cmp {bool operator()(const pair<int, char> &a, const pair<int, char> &b) {if (a.first == b.first) {return a.second > b.second;} else {return a.first > b.first;}}};
#include<bits/stdc++.h>
#define endl "\n"
#define _  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define min_heap priority_queue <int, vector<int>, greater<int> >
#define max_heap priority_queue <int>
#define ll long long
//#define int long long
#define MOD 1000000007#define deb3(x,y,z) cout << #x << "=" << x << "\t"<<#y<<"="<<y<< "\t"<<#z<<"="<<z<<endl;
#define DEBUG cout<<"Hello1\n";
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x,y) cout << #x << "=" << x << "\t\t"<<#y<<"="<<y<<endl;
#define deb3(x,y,z) cout << #x << "=" << x << "\t"<<#y<<"="<<y<< "\t"<<#z<<"="<<z<<endl;
#define all(v) (v).begin(),(v).end()
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	ll mid = (sum) / n;
	ll mid2 = mid + 1;


	ll ans1 = 0, ans2 = 0;
	for (auto x : a) {
		ans1 += (x - mid) * (x - mid);
		ans2 += (x - mid2) * (x - mid2);
	}

	cout << min(ans2, ans1);
}

int32_t main() {
_
	solve();
}

