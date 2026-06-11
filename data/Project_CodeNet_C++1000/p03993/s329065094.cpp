#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll count = 0;
    vector<set<ll>> A;
    cin >> N;
    A.resize(N);
    for(ll i = 0;i < N;i++) {
        ll temp;
        cin >> temp;
        A[i].insert(temp - 1);
    }
    for(ll i = 0;i < N;i++) {
        for(auto &j: A[i]) {
            if(i < j && A[j].find(i) != A[j].end()) count++;
        }
    }
    cout << count << endl;
    return 0;
}
