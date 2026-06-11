#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int H, W;
    string a;
    cin >> H >> W;
    rep(i, W + 2){
        cout << "#";
    }
    cout << endl;
    rep(i, H){
        cin >> a;
        cout << "#";
        rep(j, W){
            cout << a[j];
            }
        cout << "#" << endl;
        }
    rep(i, W + 2){
        cout << "#";
    }
    cout << endl;
}