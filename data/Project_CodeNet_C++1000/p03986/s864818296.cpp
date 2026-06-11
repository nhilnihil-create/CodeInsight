//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    string S;
    cin >> S;

    int k=0;
    int j=0;
    rep(i, S.size()) {
        if(S[i] == 'S') {
            k++;
        } else if(k) {
            k--;
        } else {
            j++;
        }
    }
    cout << k + j << endl;
}