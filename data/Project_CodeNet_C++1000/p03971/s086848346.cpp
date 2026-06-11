#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    ll pass = 0, bPass = 0;
    for(ll i = 0; i < N; i++) {
        if(pass < A + B && (S[i] == 'a' || (S[i] == 'b' && bPass < B))) {
            cout << "Yes" << endl;
            pass++;
            if(S[i] == 'b') {
                bPass++;
            }
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}