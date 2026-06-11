#include <bits/stdc++.h>
using namespace std;

#define mk make_pair

const int MAXN = 112345;
const double PI = atan(1) * 4;
const int MOD = 1e9 + 7;

//first = a - second = b
pair<int, int> sum_s[MAXN], sum_t[MAXN];

int main() {

	string s, t;
	cin >> s >> t;
	
	for(int i = 1; i <= s.size(); i++) {
		sum_s[i].first = (s[i-1] == 'A' ? 1 : 0);
		sum_s[i].second = (s[i-1] == 'B' ? 1 : 0);
		
		if(i > 0) {
			sum_s[i].first += sum_s[i-1].first;
			sum_s[i].second += sum_s[i-1].second;
		}
		
	}
	
	for(int i = 1; i <= t.size(); i++) {
		sum_t[i].first = (t[i-1] == 'A' ? 1 : 0);
		sum_t[i].second = (t[i-1] == 'B' ? 1 : 0);
		
		if(i > 0) {
			sum_t[i].first += sum_t[i-1].first;
			sum_t[i].second += sum_t[i-1].second;
		}
	}
	
	int query;
	cin >> query;
	
	while(query--) {
		
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		int sum_a = sum_s[b].first - sum_s[a-1].first + 2*(sum_s[b].second - sum_s[a-1].second);
		int sum_b = sum_t[d].first - sum_t[c-1].first + 2*(sum_t[d].second - sum_t[c-1].second);;
		
		if(sum_a % 3 == sum_b % 3) cout << "YES\n";
		else cout << "NO\n";
		
	}

    return 0;
}
