#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {

	int n;
	scanf("%d", &n);
	list<int> li;
	int in;
	if (n & 1) {
		for (int i = 0; i < n; i++) {
			cin >> in;
			i & 1 ? li.push_back(in) : li.push_front(in);
		}
	} else {
		for (int i = 0; i < n; i++) {
			cin >> in;
			i & 1 ? li.push_front(in) : li.push_back(in);
		}
	}
	for (auto it = li.begin(); it != li.end(); ++it)
		cout << *it << ' ';
}
