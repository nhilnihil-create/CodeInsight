#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    ll a[n];
    ll b[n];

    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
    }

    pair<ll, ll> x[n];
    x[0].first = a[0];
    x[0].second = 1;
    rep(i, 1, n){
        if(a[i - 1] < a[i]){
            x[i].second = 1;
        }else if(a[i - 1] == a[i]){
            x[i].second = 0;
        }else{
            cout << 0 << endl;
            return 0;
        }
        x[i].first = a[i];
    }

    if(x[n - 1].second == 1){
        if(x[n - 1].first != b[n - 1]){
            cout << 0 << endl;
            return 0;
        }else{
            x[n - 1].first = b[n - 1];
            x[n - 1].second = 1;
        }
    }else{
        if(x[n - 1].first < b[n - 1]){
            cout << 0 << endl;
            return 0;
        }else{
            x[n - 1].first = b[n - 1];
            x[n - 1].second = 1;
        }
    }
    rrep(i, n - 2, 0){
        if(b[i + 1] < b[i]){
            if(x[i].second == 1){
                if(x[i].first != b[i]){
                    cout << 0 << endl;
                    return 0;
                }else{
                    x[i].first = b[i];
                    x[i].second = 1;
                }
            }else{
                if(x[i].first < b[i]){
                    cout << 0 << endl;
                    return 0;
                }else{
                    x[i].first = b[i];
                    x[i].second = 1;
                }
            }
        }else if(b[i + 1] == b[i]){
            if(x[i].second == 1){
                if(x[i].first > b[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                x[i].first = min(x[i].first, b[i]);
            }
        }else{
            cout << 0 << endl;
            return 0;
        }
    }

    ll sum = 1;
    rep(i, 0, n){
        if(x[i].second == 0){
            sum *= x[i].first % 1000000007;
            sum %= 1000000007;
        }
    }

    cout << sum << endl;
    return 0;
}
