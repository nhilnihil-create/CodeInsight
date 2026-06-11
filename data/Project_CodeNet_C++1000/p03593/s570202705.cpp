//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) {
        cin >> a[i];
    }

    vi vec(26);
    rep(i, h) {
        rep(j, w) {
            vec[a[i][j]-'a']++;
        }
    }

    vi amari(4);
    rep(i, 26) {
        ++amari[vec[i]%4];
    }

    bool flag;

    if(!(1&h) && !(1&w)) {
        if(amari[1] || amari[2] || amari[3]) {
            flag = false;
        } else {
            flag = true;
        }
    } else if((h+w)&1) {
        if(amari[1] || amari[3]) {
            flag = false;
        } else if((h&1) && (w/2&1) == (amari[2]&1)) {
            flag = true;
            if(w/2 < amari[2]) flag = false;
        } else if((w&1) && (h/2&1) == (amari[2]&1)) {
            flag = true;
            if(h/2 < amari[2]) flag = false;
        } else {
            flag = false;
        }
    } else {
        if(amari[3]) {
            flag = false;
        } else if(amari[1] != 1) {
            flag = false;
        } else if(((h-1)/2+(w-1)/2&1) == (amari[2]&1)) {

            flag = true;
        } else {
            flag = false;
        }
    }




    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}