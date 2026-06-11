#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	string s;
	cin >> s;
	while(1) {
		s.pop_back();
		string x = s.substr(0, s.size() / 2);
		string y = s.substr(s.size() / 2, s.size() / 2);
		if (x == y) {
			cout << x.size()+y.size() << endl;
			return 0;
		}
	}
}
