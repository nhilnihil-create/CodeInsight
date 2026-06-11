#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
    int n, W, ans = 0;
    cin >> n >> W;
    vector<int> w1, w2, w3, w4;
    int w0, v0;
    cin >> w0 >> v0;
    w1.push_back(v0);
    for(int i = 1; i < n; i++) {
        int w, v;
        cin >> w >> v;
        if(w == w0) {
            w1.push_back(v);
        }
        else if(w == w0+1) {
            w2.push_back(v);
        }
        else if(w == w0+2) {
            w3.push_back(v);
        }
        else if(w == w0+3) {
            w4.push_back(v);
        }
    }

    sort( w1.begin(), w1.end(), greater<int>() );
    sort( w2.begin(), w2.end(), greater<int>() );
    sort( w3.begin(), w3.end(), greater<int>() );
    sort( w4.begin(), w4.end(), greater<int>() );

    rep(i, w1.size()+1) {
        rep(j, w2.size()+1) {
            rep(k, w3.size()+1) {
                rep(l, w4.size()+1) {
                    ll sumWeight = (ll)(i+j+k+l)*w0 + (j+2*k+3*l);
                    
                    if(W < sumWeight) {
                        continue;
                    }

                    int sumValue = 0;
                    rep(h, i) {
                        sumValue += w1[h];
                    }
                    rep(h, j) {
                        sumValue += w2[h];
                    }
                    rep(h, k) {
                        sumValue += w3[h];
                    }
                    rep(h, l) {
                        sumValue += w4[h];
                    }

                    ans = max(ans, sumValue);
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}