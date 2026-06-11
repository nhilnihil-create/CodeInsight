#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll ans = 1;
    ll inc = 0;//1=inc--2=dec
    for(ll i = 0; i < A.size() - 1; i++) {
        if (A.at(i) == A.at(i + 1)) {
            A.erase(A.begin() + i + 1);
            i--;
        }
    }
    N = A.size();
    for(ll i = 1; i < N - 1; i++) {
        if((A.at(i - 1) - A.at(i))*(A.at(i) - A.at(i + 1)) < 0) {
            ans++;
            A.at(i) = A.at(i + 1);
            //cout << i << ':' << ((A.at(i - 1) - A.at(i))*(A.at(i) - A.at(i + 1)) < 0) << endl;
        }
    }

    cout << ans << endl;
    


    return 0;
}