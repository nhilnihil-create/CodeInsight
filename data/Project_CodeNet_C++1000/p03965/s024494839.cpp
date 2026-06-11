#include <bits/stdc++.h>
using namespace std;

signed main () {
	string s;
    cin >> s;
    map < char, int > took;
    int points = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'g') {
            if (took['p'] < took['g']) {
                ++took['p'];
                ++points;
            }
            else 
                ++took['g'];
        }
        else if (s[i] == 'p') {
            if (took['p'] < took['g'])
                ++took['p'];
            else {
                ++took['g'];
                --points;
            }
        }
    }
    cout << points << '\n';
}
