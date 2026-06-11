#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll mode = 0;
    ll N;
    ll count = 1;
    ll prev;
    cin >> N;
    cin >> prev;
    for(ll i = 1;i < N;i++) {
        ll temp;
        ll nm = 0;
        cin >> temp;
        if(temp > prev) nm = 1;
        else if(temp < prev) nm = -1;
        if(mode == 0) {
            mode = nm;
        } else if(nm != 0 && mode != nm) {
            count++;
            mode = 0;
        }
        prev = temp;
    }
    cout << count << endl;
    return 0;
}
