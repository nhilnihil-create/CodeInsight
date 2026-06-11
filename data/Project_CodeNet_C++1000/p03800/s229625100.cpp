#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; scanf("%d", &n);
	std::string s; cin >> s;

	for(int latte = 0; latte < 4; latte++) {
		std::string t(n, ' ');
		t[0] = (latte % 2 ? 'S' : 'W');
		t[1] = (latte / 2 ? 'S' : 'W');

		auto flip = [](char c) {
			if(c == 'S') return 'W';
			return 'S';
		};

		std::string u = t;
		for(int i = 1; i < n; i++) {
			if(s[i] == 'o') {
				if(t[i] == 'S') t[(i + 1) % n] = t[(i - 1 + n) % n];
				if(t[i] == 'W') t[(i + 1) % n] = flip(t[(i - 1 + n) % n]);
			} else {
				if(t[i] == 'W') t[(i + 1) % n] = t[(i - 1 + n) % n];
				if(t[i] == 'S') t[(i + 1) % n] = flip(t[(i - 1 + n) % n]);
			}
		}

		bool f = (t.substr(0, 2) == u.substr(0, 2));
		if(s[0] == 'o') {
			if(t[0] == 'S') f &= (t[n - 1] == t[1]);
			if(t[0] == 'W') f &= (t[n - 1] != t[1]);
		} else {
			if(t[0] == 'W') f &= (t[n - 1] == t[1]);
			if(t[0] == 'S') f &= (t[n - 1] != t[1]);	
		}
		if(!f) continue;
		
		cout << t << endl;
		return 0;
	}
	printf("-1\n");
	return 0;
}
