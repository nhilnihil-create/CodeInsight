#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
    a.at(tmp - 1) = i;
	}
	set<int> s;
	s.insert(-1);
	s.insert(n);
	long long int ans = 0;
  for (int i = 0; i < n; i++) {
		auto itr = s.upper_bound(a.at(i));
		long long int l = *itr - a.at(i);
		long long int r = a.at(i) - *(--itr);
		ans += (i + 1) * l * r;
		s.insert(a.at(i));
	}
	cout << ans << endl;
	return 0;
}
