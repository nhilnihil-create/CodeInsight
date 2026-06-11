#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
string s;


void input() {
    cin >> s;
}


int main() {
    input();
    s[5] = s[13] = ' ';
    cout << s << endl;
}
