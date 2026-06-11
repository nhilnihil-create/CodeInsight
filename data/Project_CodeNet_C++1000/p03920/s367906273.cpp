#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;

bool C(ll k){
    ll sum = k * (k + 1) / 2;
    return sum >= n;
}

int main(){
    cin >> n;

    ll ok = n, ng = 0;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if (C(mid)) ok = mid;
        else ng = mid;
    }

    ll s = ok * (ok + 1) / 2;
    for (int i = 1; i <= ok; ++i) {
        if (i == s - n) continue;
        cout << i << endl;
    }
}