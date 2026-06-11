#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() { 
    int H, W;
    string inp;
    vector<string> C;
    cin >> H >> W;
    rep(i, H){
        cin >> inp;
        C.push_back(inp);
    }
    rep(i, H) {
        cout << C.at(i) << "\n";
        cout << C.at(i) << "\n";
    }

    return 0;
}
