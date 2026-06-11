#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int H, W, s_size;
    cin >> H >> W;
    vector<string> v;
    rep(i, H){
        string s;
        cin >> s;
        v.push_back("#"+s+"#");
        s_size = s.size();
    }

    rep(i,s_size+2){
        cout << "#";
    }
    cout << endl;
    rep(i,H){
        cout << v[i] << endl;
    }

    rep(i,s_size+2){
        cout << "#";
    }
    cout << endl;



    return 0;
}
