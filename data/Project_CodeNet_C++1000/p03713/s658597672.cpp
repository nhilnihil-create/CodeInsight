#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    ll h, w;
    cin >> h >> w;
    ll a, b, c;
    ll mi = 100000000;

    for(int i = 1; i < h ; i++){
        a = i * w;
        b = ceil((h - i) / 2.0) * w;
        c = floor((h - i) / 2.0) * w;
        ll dif = max(a, max(b, c)) - min(a, min(b, c));
        mi = min(dif, mi);

        b = ceil(w / 2.0) * (h - i);
        c = floor(w / 2.0) * (h - i);
        dif = max(a, max(b, c)) - min(a, min(b, c));
        mi = min(dif, mi);
    }

    swap(h, w);
    for(int i = 1; i < h ; i++){
        a = i * w;
        b = ceil((h - i) / 2.0) * w;
        c = floor((h - i) / 2.0) * w;
        ll dif = max(a, max(b, c)) - min(a, min(b, c));
        mi = min(dif, mi);

        b = ceil(w / 2.0) * (h - i);
        c = floor(w / 2.0) * (h - i);
        dif = max(a, max(b, c)) - min(a, min(b, c));
        mi = min(dif, mi);
    }

    cout << mi << endl;
    return 0;
}
