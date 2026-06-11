#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int H,W;
    cin >> H >> W;

    vector<string> A(H);

    rep2(i, 0, H){
        cin >> A.at(i);
    }

    vector<char> sharp(W+2, '#');

    rep2(i, 0, W+2) cout << sharp.at(i);
    cout << endl;

    rep2(i, 0, H) cout << '#' + A.at(i) + '#' << endl;

    rep2(i, 0, W+2) cout << sharp.at(i);
    cout << endl;
}
