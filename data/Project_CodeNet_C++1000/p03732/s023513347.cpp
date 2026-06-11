#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, w;
    cin >> n >> w;

    vector<ll> w1;
    vector<ll> w2;
    vector<ll> w3;
    vector<ll> w4;
    ll w0;
    ll tmp;
    cin >> w0 >> tmp;
    w1.push_back(tmp);

    rep(i, 0, n-1){
        ll t1, t2;
        cin >> t1 >> t2;

        if(t1 == w0){
            w1.push_back(t2);
        }else if(t1 == w0 + 1){
            w2.push_back(t2);
        }else if(t1 == w0 + 2){
            w3.push_back(t2);
        }else if(t1 == w0 + 3){
            w4.push_back(t2);
        }
    }

    sort(w1.begin(), w1.end(), greater<ll>());
    sort(w2.begin(), w2.end(), greater<ll>());
    sort(w3.begin(), w3.end(), greater<ll>());
    sort(w4.begin(), w4.end(), greater<ll>());

    if(w1.size())
    rep(i, 0, w1.size() - 1){
        w1[i + 1] = w1[i] + w1[i + 1];
    }
    if(w2.size())
    rep(i, 0, w2.size() - 1){
        w2[i + 1] = w2[i] + w2[i + 1];
    }
    if(w3.size())
    rep(i, 0, w3.size() - 1){
        w3[i + 1] = w3[i] + w3[i + 1];
    }
    if(w4.size())
    rep(i, 0, w4.size() - 1){
        w4[i + 1] = w4[i] + w4[i + 1];
    }

    ll ans = 0;
    rep(i, 0, w1.size() + 1){
        rep(j, 0, w2.size() + 1){
            rep(k, 0, w3.size() + 1){
                rep(l, 0, w4.size() + 1){
                    ll v = 0;
                    if(i * w0 + j * (w0 + 1) + k * (w0 + 2) + l * (w0 + 3) > w)continue;
                    if(i != 0)
                        v += w1[i - 1];
                    if(j != 0)
                        v += w2[j - 1];
                    if(k != 0)
                        v += w3[k - 1];
                    if(l != 0)
                        v += w4[l - 1];
                    ans = max(v, ans);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;

}
