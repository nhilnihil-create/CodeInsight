#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;
    int cnt = s.size() - 2;
    cout << s[0] << cnt << s[s.size()-1] << endl;

    return 0;
}