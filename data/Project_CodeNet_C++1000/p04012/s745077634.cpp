#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    string w;
    cin >> w;
    vector<int> alpha(26);
    vector<int> num(26);
    alpha.at(0) = 'a';
    rep(i,26) alpha.at(i) = 'a' + i;
    rep(i, w.size()){
        rep(j,26){
            if(w.at(i) == alpha.at(j)) num.at(j)++;
        }
    }
    int ans = 0;
    rep(i, 26){
        if(num.at(i) % 2 == 1){
            cout << "No" << endl;
            break;
        }
        if(i == 25) cout << "Yes" << endl;
    }
}
