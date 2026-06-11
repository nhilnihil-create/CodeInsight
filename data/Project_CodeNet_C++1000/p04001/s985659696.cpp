// ARC_061_C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >>s;

	int n = s.size();
	vector<int> v(n);
	for(int i = 0; i < n; ++i) v[i] = s[i];

	ll sum = 0;
	
	for(int tmp = 0; tmp < (1 << (n-1)); ++tmp) {
		ll pos = 0;
		for(int i = 0; i < n-1; ++i) {
			if(tmp & (1 << i)) {
				string sub = s.substr(pos, i-pos+1);
				sum += stoll(sub);
				pos = i + 1;
			}
		}
		string sub = s.substr(pos, n);
		sum += stoll(sub);                 
	} 

	cout << sum << "\n";

	return 0;
}