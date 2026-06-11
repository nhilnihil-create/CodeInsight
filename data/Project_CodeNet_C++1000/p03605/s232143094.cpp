#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
string N;


void input() {
    cin >> N;
}


int main() {
    input();
    int c = count(N.begin(), N.end(), '9');
    string ans;
    if (c > 0) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
