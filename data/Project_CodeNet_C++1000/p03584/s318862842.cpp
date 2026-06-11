#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif


void solve(ll N, ll K, vector<ll> A, vector<ll> B) {
    ll ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (K >> i & 1) {
            ll L = K ^ (1 << i) | ((1 << i) - 1);

            ll sub = 0;
            for (int k = 0; k < N; k++) {
                if ((L | A[k]) == L) {
                    sub += B[k];
                }
            }
            ans = max(ans, sub);
        }
    }
    {
        ll sub = 0;
        for (int k = 0; k < N; k++) {
            if ((K | A[k]) == K) {
                sub += B[k];
            }
        }
        ans = max(ans, sub);
    }
    cout << ans << endl;
}


void main_(istream &cin) {
    ll K;
    ll N;
    cin >> N;
    vector<ll> A(N - 1 + 1);
    vector<ll> B(N - 1 + 1);
    cin >> K;
    for (int i = 0; i <= N - 1; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    solve(N, K, A, B);
}

int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}



