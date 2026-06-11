#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int pa, pz;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'A') {
            pa = i;
            break;
        }
    }

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'Z') pz = i;
    }

    cout << pz - pa + 1 << endl;
}