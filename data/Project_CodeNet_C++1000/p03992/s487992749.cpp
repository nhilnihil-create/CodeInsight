#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    cout << s.substr(0,4) << " " << s.substr(4,s.size()-4) << endl;
    return 0;
}