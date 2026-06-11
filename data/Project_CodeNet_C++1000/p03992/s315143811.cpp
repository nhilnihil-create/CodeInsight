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
    string s;
    cin >> s;
    string ans = s.substr(0, 4) + " " + s.substr(4, 8);
    cout << ans << '\n';
}