#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MLOG = 63;

struct gavi{                    //  l : -------------      r : ---------------
	deque <int> r, l;           //      ^           ^          ^             ^
	void push_back(int x) {     //    front        back      midl           far
		l.push_back(x);
	}
	void push_midl(int x) {
		r.push_front(x);
	}
	void push_frnt(int x) {
		l.push_front(x);
	}
	void push_far(int x) {
		r.push_back(x);
	}
	void out() {
		cout << l.size() + r.size() << endl;
		for (int i : l) 
			cout << i << ' ';
		for (int i : r)
			cout << i << ' ';
	}
} me;

int main() {
	ll n;
	cin >> n;
	vector <int> l, r;
	int cnt = 1;
	vector <bool> all;
	while (n) {
		if (n & 1) {
			all.push_back(false);
			n /= 2;
		} else {
			all.push_back(true);
			n--;
		}
	}
	reverse(all.begin(), all.end());
	for(int i = 0; i < (int)all.size(); i++) {
		cerr << all[i];
		if(all[i]) {
			me.push_back(cnt);
			me.push_midl(cnt++);
		} else {
			me.push_frnt(cnt);
			me.push_midl(cnt++);
		}
	}
	cerr << endl;
	me.out();
}
