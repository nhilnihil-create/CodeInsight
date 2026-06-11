#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> x(M), y(M);
    rep(i,M) {
        cin >> x.at(i) >> y.at(i);
        --x.at(i);
        --y.at(i);
    }
    vector<int> num(N, 1);
    vector<bool> ans(N, false);
    ans.at(0) = true; 
    rep(i,M) {
        if (ans.at(x.at(i)) == true) {
            ans.at(y.at(i)) = true;
            if (num.at(x.at(i)) == 1) ans.at(x.at(i)) = false;
        }
        --num.at(x.at(i));
        ++num.at(y.at(i));
    }
    cout << count(ans.begin(), ans.end(), true) << endl;
}
