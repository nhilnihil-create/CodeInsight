#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

template <typename T>
using lim = numeric_limits<T>;

int arr[26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 26; i++) arr[i] = -1;
	string s; cin >> s;

	int n = s.size();

	int l, r;
	l = r = -1;
	for (int i = 0; i < n; i++){
		int x = s[i]-'a';
		if (arr[x] == -1) arr[x] = i;
		else {
			if (i-arr[x]+1 <= 3) {
				l = arr[x]+1;
				r = i+1;
				break;
			}
			arr[x] = i;
		}
	}

	cout << l << " " << r << "\n";
}