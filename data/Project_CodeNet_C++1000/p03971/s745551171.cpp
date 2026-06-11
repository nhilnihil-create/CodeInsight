#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    int pass = 0;
    int pass_B = 0;

    rep(i,S.size()) {
        if (S[i] == 'a') {
             if (pass < A + B) {
                 cout << "Yes" << endl;
                 ++pass;
             } else cout << "No" << endl;
        } else if (S[i] == 'b') { 
            if (pass < A + B && pass_B < B) {
                cout << "Yes" << endl;
                ++pass;
                ++pass_B;
            } else cout << "No" << endl;
        } else cout << "No" << endl;
    }
}

