#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(int) n; i++)

using namespace std;
typedef long long ll;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int acc = n * 2;

    for (int i = n; i >= 0; i--) {
        string si = s.substr(s.length() - i, i);
        if (t.find(si) == 0) {
            cout << acc - i << endl;
            return 0;
        }
    }
}