#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i,h) {
        cin >> s.at(i);
    }

    vector<vector<char>> a(h+2, vector<char>(w+2));
    rep(i,h+2) {
        rep(j,w+2) {
            a.at(i).at(j)='#';
        }
    }
    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            a.at(i).at(j)=s[i-1].at(j-1);
         }
    }

    rep(i,a.size()) {
        rep(j,a.at(0).size()) {
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}