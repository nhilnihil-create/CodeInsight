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

    ll n;
    cin >> n;

    ll a[n];
    rep(i, 0, n){
        cin >> a[i];
    }

    ll x[h][w];
    ll c_a = 0;
    rep(i, 0, h){
        if(i % 2 == 0){
            rep(j, 0, w){
                x[i][j] = c_a + 1;
                a[c_a]--;
                if(a[c_a] == 0){
                    c_a++;
                }
            }
        }else{
            rrep(j, w - 1, 0){
                x[i][j] = c_a + 1;
                a[c_a]--;
                if(a[c_a] == 0){
                    c_a++;
                }
            }
        }
    }

    rep(i, 0, h){
        rep(j, 0, w){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
