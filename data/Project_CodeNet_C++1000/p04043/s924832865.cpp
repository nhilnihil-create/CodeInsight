#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b,c; cin >> a >> b >> c;
    map <int,int> mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    if (mp[5] == 2 && mp[7] == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}