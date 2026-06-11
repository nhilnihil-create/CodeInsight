#include <bits/stdc++.h>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    string S1, S2;
    cin>>N>>S1>>S2;

    ll ans;
    bool prev;
    ll n = 0;
    if (S1[0] == S2[0]) {
        ans = 3;
        prev = false;
        n = 1;
    } else {
        ans = 6;
        prev = true;
        n = 2;
    }
    // prev == false
    // X
    // X
    //
    // prev == true
    // XX
    // YY
    while (n < N) {
        if (S1[n] == S2[n]) {
            n++;
            if (!prev) ans = ans * 2 % inf;
            prev = false;
        } else {
            n += 2;
            if (!prev) ans = ans * 2 % inf;
            else ans = ans * 3 % inf;
            prev = true;
        }
    }
    cout<<ans<<endl;
    return 0;
}