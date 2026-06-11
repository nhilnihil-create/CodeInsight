#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    set<int> water, sugar;
    rep(i, F) {
        rep(j, F) {
            if (100*(A*i + B*j) <= F) {
                water.insert(100*A*i + 100*B*j);
            }
            if (C*i + D*j <= F) {
                sugar.insert(C*i + D*j);
            }
        }
    }
    vector<int> w(water.begin(), water.end()), s(sugar.begin(), sugar.end());
    int denth1=0, denth2 = 1;
    int ansW=w[w.size()-1], ansS=0;
    rep(i, w.size()) {
        rep(j, s.size()) {
            if (w[i]+s[j] > 0 && w[i] + s[j] <= F && denth1*(w[i]+s[j]) < s[j]*denth2 && s[j] <= w[i]/100*E) {
                ansW = w[i]; ansS = s[j];
                denth1 = s[j]; denth2 = w[i]+s[j];
            }
        }
    }
    //cout << denth << endl;
    cout << ansW+ansS << " " << ansS << endl;
}
