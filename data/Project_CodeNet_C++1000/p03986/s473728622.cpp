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
	string x;
	cin >> x;

	int s = 0, t= 0;

	for(int i = 0; i < x.size(); i++) {
		if(x[i] == 'S') {
			s++;
		} else {
			if(s > 0) s--;
			else t++;
		}
	}

	cout << s + t << endl;

	return 0;
}