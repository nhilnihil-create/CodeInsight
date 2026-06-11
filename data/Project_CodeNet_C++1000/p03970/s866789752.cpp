#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
/* main */
int main(){
    string t;
    cin >> t;

    string ac = "CODEFESTIVAL2016";
    int ans = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != ac[i]) {
            ans++;
        }
    }

    cout << ans << '\n';
}