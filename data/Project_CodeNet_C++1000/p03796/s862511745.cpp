#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const long long MOD = 1e9+7;


ll kaij(ll n) {
    if(n == 1) {
        return 1;
    }
    return n*kaij(n - 1)%MOD;
}

int main() {
    ll N = 0;
    cin >> N;

    cout << kaij(N) << endl;


    return 0;
}