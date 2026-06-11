#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	int n, k;
	set<int> d;
	vi num;
	cin >> n >> k;
	for(int i=0; i<k; i++) {
		int temp;
		cin >> temp;
		d.insert(temp);
	}
	while(n) {
		num.push_back(n%10);
		n/=10;
	}
	reverse(num.begin(), num.end());
	vi sol;
	bool in = false;
	for(int i = 0; i < num.size(); i++) {
		int a = (in ? 0 : num[i]);
		while(d.find(a) != d.end()) {
			a++;
			in = true;
		}
		
		if(a <= 9) sol.push_back(a);
		else {
			a = 1;
			while(d.find(a) != d.end()) a++;
			cout << a;
			int b = 0;
			while(d.find(b) != d.end()) b++;
			for(int j = 0; j < num.size(); j++) cout << b;
			cout << endl;
			return 0;
		}
	}
	for(int a : sol) cout << a;
	cout << endl;
	return 0;
}