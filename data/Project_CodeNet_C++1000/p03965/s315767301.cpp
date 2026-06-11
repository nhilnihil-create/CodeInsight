#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int x=0,g=0,p=0,r=0;
	string s;
	cin >> s;

	rep(i,s.size())
		if(s.at(i) == 'p')
			++x;
	
	rep(i,s.size()) {
		int t=s.size()-1-i;

		if(s.at(t) == 'p') {
			if(p < g)
				++p;
			else
				++g, --r;
			--x;
		} else {
			if(g-p > x)
				++p, ++r;
			else
				++g;
		}
	}

	cout << r << endl;
}