#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w;
    cin >> h >> w;
    vector<int> a(26);
    rep(i, h) rep(j, w) {
        char tmp_a;
        cin >> tmp_a;
        ++a[tmp_a-'a'];
    }

//    rep(i, 26) cout << a[i] << " ";
//    cout << endl;

    int g1 = 0;
    int g2 = 0;
    int g4;
    if ( (h&1) && (w&1) ) g1 = 1;

    if ( (h&1) && (w&1) ) g2 = ( h - 1 + w - 1 ) / 2;
    else if ( (h&1)     ) g2 = w / 2;
    else if ( (w&1)     ) g2 = h / 2;

    if ( (h&1) && (w&1) ) g4 = ( h - 1 ) * ( w - 1 ) / 4;
    else if ( (h&1)     ) g4 = ( h - 1 ) * w / 4;
    else if ( (w&1)     ) g4 = ( w - 1 ) * h / 4;
    else                  g4 = h * w / 4;

    int cnt = 0;
    rep(i, 26) {
        if ( cnt == g1 ) break;
        if ( a[i] % 4 == 1 || a[i] % 4 == 3 ) {
            --a[i];
            ++cnt;
        }
    }

    cnt = 0;

    rep(i, 26) {
        if ( cnt == g2 ) break;
        while(1) {
            if ( a[i] % 4 != 2 ) break;
            a[i] -= 2;
            ++cnt;
        }
    }
    int cntg2 = cnt;

    cnt = 0;
    rep(i, 26) {
        if ( a[i] == 0 ) continue;
        while(1) {
            if ( a[i] % 4 != 0 || a[i] == 0 ) break;
            if ( cnt == g4 && cntg2 == g2 ) {
                break;
            }
            if ( cnt == g4 && cntg2 < g2 ) {
                cntg2 += 2;
            } 
            else {
                ++cnt;
            }
            a[i] -= 4;
        }
    }

    rep(i, 26) {
//        cout << a[i] << endl;
        if ( a[i] != 0 ) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
