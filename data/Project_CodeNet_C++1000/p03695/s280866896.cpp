#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	int n = 0;
	cin >> n;
	long long count = 0, rating = 0;
	set<string> s;
	for (int i = 0; i < n; i++) {
		cin >> rating;
		if (rating >= 1 && rating <= 399)
			s.insert("grey");
		else if (rating >= 400 && rating <= 799)
			s.insert("brown");
		else if (rating >= 800 && rating <= 1199)
			s.insert("green");
		else if (rating >= 1200 && rating <= 1599)
			s.insert("cyan");
		else if (rating >= 1600 && rating <= 1999)
			s.insert("blue");
		else if (rating >= 2000 && rating <= 2399)
			s.insert("yellow");
		else if (rating >= 2400 && rating <= 2799)
			s.insert("orange");
		else if (rating >= 2800 && rating <= 3199)
			s.insert("red");
		else
			count++;
	}
	if (s.size() > 0)
		cout << s.size() << " " << (long long) s.size() + count << endl;
	else if (count > 0)
		cout << 1 << " " << count << endl;
	else
		cout << 0 << " " << 0 << endl;
	return 0;
}
