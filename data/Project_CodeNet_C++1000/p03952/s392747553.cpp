#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, x;
    cin >> n >> x;

    if(x == 1 || x == 2 * n - 1){
        cout << "No" << endl;
        return 0;
    }else{
        cout << "Yes" << endl;
    }

    if(n == 2){
        cout << 1 << endl << 2 << endl << 3;
    }else{
        vector<ll> a;
        if(x == 2){
            rep(i, 1, 2 * n){
                if(i != x - 1 && i != x && i != x + 1 && i != x + 2){
                    a.push_back(i);
                }
            }
            rep(i, 1, 2 * n){
                if(i != n - 1 && i != n && i != n + 1 && i != n + 2){
                    cout << a.back() << endl;
                    a.pop_back();
                }
                if(i == n - 1){
                    cout << x - 1 << endl;
                }else if(i == n){
                    cout << x << endl;
                }else if(i == n + 1){
                    cout << x + 1 << endl;
                }else if(i == n + 2){
                    cout << x + 2 << endl;
                }
            }

        }else{
            rep(i, 1, 2 * n){
                if(i != x - 1 && i != x && i != x + 1 && i != x - 2){
                    a.push_back(i);
                }
            }
            rep(i, 1, 2 * n){
                if(i != n - 1 && i != n && i != n + 1 && i != n + 2){
                    cout << a.back() << endl;
                    a.pop_back();
                }
                if(i == n - 1){
                    cout << x - 1 << endl;
                }else if(i == n){
                    cout << x << endl;
                }else if(i == n + 1){
                    cout << x + 1 << endl;
                }else if(i == n + 2){
                    cout << x - 2 << endl;
                }
            }
        }
    }
    return 0;
}
