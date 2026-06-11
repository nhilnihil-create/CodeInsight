#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {FIN
    
    int i = 0;
    string s, r = "";
    cin >> s;
    for (i = 0; i < s.size(); i++) {
		if (s[i] == 'B') {
			if (r.size() > 0)
				r.pop_back();
		} else
			r += s[i];
	}
	cout << r << "\n";
    
    return 0;
}
