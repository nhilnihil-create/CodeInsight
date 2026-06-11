#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a = 0, b = 0;
    char s;

    cin >> a >> s >> b;

    if(s == '+') {
        cout << a + b << endl;
    }
    else {
        cout << a - b << endl;
    }
    
    return 0;
}