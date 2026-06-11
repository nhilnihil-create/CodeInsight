#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main() {
    string s; cin >> s;
    ll cnt = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] != s[i]) cnt++;
    }
    cout << cnt << endl;
}
