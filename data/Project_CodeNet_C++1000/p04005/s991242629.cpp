#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    vector<ll> abc(3);
    rep(i, 3)cin >> abc[i];
    sort(all(abc));
    if(abc[2]%2 == 1) {
        ll r = abc[0] * abc[1] * (abc[2] / 2 + 1);
        ll b = abc[0] * abc[1] * (abc[2] / 2);
        cout << r - b << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}