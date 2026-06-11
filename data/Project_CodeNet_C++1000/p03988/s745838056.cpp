 #include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5 + 9;

bool valid(const vector<int> &v) {
	int cnt = 0, table[109];
	for (int i = 0; i < 109; i++) {
		table[i] = 0;
	}
	for (auto ch : v) {
		if (ch == INF) continue;
		table[ch]++;
		cnt++;
	}
	if (cnt == 1 && table[0] == 1) return true;
	if (cnt == 2 && table[1] == 2) return true;
	return false;
} 

void print_vec(const vector<int> &v) {
	for (auto vi : v) {
		cout << vi << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, len = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a >= n) {
			cout << "Impossible\n";
			return 0;
		}
		len = max(len, a);
		v.push_back(a);
	}
	int size = n;
	while (size >= 0 && len >= 0) {
		if (valid(v)) {
			cout << "Possible\n";
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == INF) continue; 
			if (v[i] == len) {
				v[i] = INF;
				size--;
				cnt++;
			} else {
				v[i]--;
			}
		}
		len -= 2;
		if (!cnt) {
			cout << "Impossible\n";
			return 0;
		}
//		print_vec(v);
	}
	cout << "Impossible\n";
	
	return 0;
}
