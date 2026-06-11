#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

int main() {
    int keep = 0, cnt1 = 0, cnt2 = 0;
    cin >> N;
    string s;
    cin >> s;
    rep(i, N){
        if(s[i] == '(') {
            keep++;
        }
        else {
            if(keep != 0) keep--;
            else cnt1++;
        }
    }
    rep(i, cnt1){
        cout << '(';
    }
    cout << s;
    rep(i, keep){
        cout << ')';
    }
}
