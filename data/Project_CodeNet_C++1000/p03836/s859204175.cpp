#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll powk(ll a, ll n = 2){
    ll r = 1;
    for(ll i = 0;i < n;i++){
        r *= a;
    }

    return r;
}


int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    ll rl = abs(sx - tx), ud = abs(sy - ty);
    for(ll i = 0;i < ud;i++){
        cout << 'U';
    }
    for(ll i = 0;i < rl;i++){
        cout << 'R';
    }
    for(ll i = 0;i < ud;i++){
        cout << 'D';
    }
    for(ll i = 0;i < rl;i++){
        cout << 'L';
    }
    cout << 'L';
    for(ll i = 0;i < ud + 1;i++){
        cout << 'U';
    }
    for(ll i = 0;i < rl + 1;i++){
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    for(ll i = 0;i < ud + 1;i++){
        cout << 'D';
    }
    for(ll i = 0;i < rl + 1;i++){
        cout << 'L';
    }
    cout << 'U';

    return 0;
}