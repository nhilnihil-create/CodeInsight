#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll h, w;
    cin >> h >> w;

    map<ll, ll> a;
    rep(i, 0, h){
        rep(j, 0, w){
            char tmp;
            cin  >> tmp;
            a[tmp]++;
        }
    }

    ll p = 0, q = 0, r = 0;
    fore(x, a){
        p += x.second / 4;
        x.second -= x.second / 4 * 4;
        q += x.second / 2;
        x.second -= x.second / 2 * 2;
        r += x.second / 1;
    }

    if(h % 2 == 0 && w % 2 == 0){
        if(p * 4 == h * w){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(h % 2 == 1 && w % 2 == 1){
        if((h - 1) * (w - 1) <= p * 4){
            q += (p * 4 - (h - 1) * (w - 1)) / 2;
            if(r == 1){
                if(q * 2 == h + w - 2){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
        return 0;
    }else if(h % 2 == 0 && w % 2 == 1){
        if((h) * (w - 1) <= p * 4){
            q += (p * 4 - (h) * (w - 1)) / 2;
            if(q * 2 == h){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }else if(h % 2 == 1 && w % 2 == 0){
        if((h - 1) * (w) <= p * 4){
            q += (p * 4 - (h - 1) * (w)) / 2;
            if(q * 2 == w){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }

    return 0;
}
