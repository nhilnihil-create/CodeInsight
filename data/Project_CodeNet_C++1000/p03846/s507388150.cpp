#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const int MOD=1e9+7;

int main() {
    int N;
    bool c=1;
    cin >> N;
    vector<int> A(N);
    rep(i,N)
        cin >> A.at(i);
    sort(A.begin(), A.end());

    if(N%2) {
        if(A.at(0) != 0)
           c=0;
        else
            rep(i,N/2)
                if(A.at((i+1)*2-1)!=(i+1)*2 || A.at((i+1)*2)!=(i+1)*2) {
                    c = 0;
                    break;
                }
    } else {
        rep(i,N/2)
            if(A.at(i*2)!=i*2+1 || A.at(i*2+1)!=i*2+1) {
                c = 0;
                break;
            }
    }

    if(c) {
        ll r = 1;
        rep(i,N/2) {
            r *= 2;
            r %= MOD;
        }
        cout << r;
    } else
        cout << 0;
    cout << endl;
}