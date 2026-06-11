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
	string s;
	cin >> s;

	set<char> ms;
	if (s[0] == s[1]) {
		cout << 1 << " " << 2;
		return;
	}
	ms.insert(s[0]);
	ms.insert(s[1]);
	for (int i = 2; i < s.size(); i++) {
		ms.insert(s[i]);
		if (ms.size() < 3) {
			cout << i - 1 << " " << i + 1;
			return;
		} else {
			ms.erase(s[i - 2]);
		}
	}

	cout << -1 << " " << -1;
}

int32_t main() {
	_

	solve();
}

