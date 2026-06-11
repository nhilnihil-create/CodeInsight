#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    ll now = 0, l, r;
    char x;
    while(true){
        l = 0, r = 10;
        if(now == 0) l = 1;
        while(r-l > 1){
            ll n = (l+r)/2;
            cout << "? " << now*10+n << endl;
            cin >> x;
            if(x == 'Y') l = n;
            else r = n;
        }
        if(l < 9){
            now = now*10+l;
            continue;
        }
        if(now == 0){
            cout << "? " << 10 << endl;
            cin >> x;
            if(x == 'N'){
                l = 1, r = 9;
                while(r-l > 1){
                    ll n = (l+r)/2;
                    cout << "? " << n*10 << endl;
                    cin >> x;
                    if(x == 'Y') r = n;
                    else l = n; 
                }
                cout << "! " << now*10+r << endl;
                break;
            }
            else{
                cout << "? " << 10000000000 << endl;
                cin >> x;
                if(x == 'Y'){
                    cout << "! " << 1 << endl;
                    break;
                }
                else{
                    now = 9;
                    continue;
                }
            }
        }
        cout << "? " << now*100 << endl;
        cin >> x;
        if(x == 'N'){
            l = 0, r = 9;
            while(r-l > 1){
                ll n = (l+r)/2;
                cout << "? " << now*100+n*10 << endl;
                cin >> x;
                if(x == 'Y') r = n;
                else l = n; 
            }
            cout << "! " << now*10+r << endl;
            break;
        }
        else{
            cout << "? " << now*1000000000 << endl;
            cin >> x;
            if(x == 'Y'){
                cout << "! " << now*10 << endl;
                break;
            }
            else{
                now = now*10+9;
                continue;
            }
        }
    }
}