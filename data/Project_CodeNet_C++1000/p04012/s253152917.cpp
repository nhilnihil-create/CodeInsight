#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

const int INF = 1000000000;

int main() {FIN
    
    int i, e;
    string s;
    cin >> s;
    vi let('z' - 'a' + 1);
    for (i = 0; i < s.size(); i++)
		let[s[i] - 'a']++;
		
	e = 1;
	for (i = 0; i < let.size(); i++)
		e = (e & !(let[i] & 1));
		
	cout << (e ? "Yes" : "No") << "\n";
    
    return 0;
}
