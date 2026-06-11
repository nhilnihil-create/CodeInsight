#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const int mod = 1e9+7;

int main() {
    ll N,r,x=0;
    string S1,S2;
    vector<ll> t;
    char p;
    cin >> N >> S1 >> S2;

    p = S1.at(0);
    if(S1.size() == 1) {
        cout << 3 << endl;
        return 0;
    }

    rep(i,N-1) {
        if(p == S1.at(i+1)) {
            t.push_back(2);
            i++;
            if(i == N-2) {
                t.push_back(1);
                break;
            } else if(i == N-1) {
                break;
            }
        } else {
            t.push_back(1);
        }
        p = S1.at(i+1);
    }

    rep(i,t.size())
        x += t.at(i);
    if(x+1 == N)
        t.push_back(1);

    if(t.at(0) == 1)
        r = 3;
    else
        r = 6;

    rep(i, t.size()-1) {
        if(t.at(i)==2 && t.at(i+1)==1)
            continue;
        else if(t.at(i)==2 && t.at(i+1)==2)
            r *= 3;
        else
            r *= 2;
        r %= mod;
    }

    cout << r << endl;    
}