#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;cin >> n;
	vector <int> a(0);
	int dodo;
	for(int i = 0; i < n; i++) {
		if(i == 0) {cin >> dodo; a.pb(dodo); continue;}
		cin >> dodo;
		if(dodo == a[a.size() - 1]) {
			continue;
		}
		a.pb(dodo);
	}

	int count = 1;
	if(a.size() == 1) {cout << 1 << endl; return 0;}
	bool I;
	if(a[1] > a[0]) I = true;
	else I = false;


	for(int i = 2; i < a.size(); i++) {
		if(a[i] < a[i -1]) /*des*/ {
			if(I) {
				count++;
				if(a[i + 1] > a[i]) I = true;
				else I = false;
				i++;
			}
		} else {//ascend
			if(!I) {
				count++;
				if(a[i + 1] > a[i]) I = true;
				else I = false;
				i++;
			}
		}
	}


	cout << count << endl;


	return 0;
}