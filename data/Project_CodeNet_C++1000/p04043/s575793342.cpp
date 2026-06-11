#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// INT VS LL

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> cnt(10);
    for (int i = 0; i < 3; ++i) {
    	int foo;
    	cin >> foo;
    	cnt[foo]++;
    }
    if (cnt[5] == 2 && cnt[7] == 1) {
    	cout << "YES";
    }
    else {
    	cout << "NO";
    }

    return 0;
}