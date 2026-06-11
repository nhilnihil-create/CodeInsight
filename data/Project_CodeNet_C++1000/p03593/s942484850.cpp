#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    ll h, w; cin >> h >> w;
    vc g(h*w);
    map<char, ll> m;
    rep(i, 0, h*w){
        cin >> g[i];
        m[g[i]]++;
    }
    if(h%2 == 0&&w%2 == 0){
        bool b = true;
        for(auto x: m){
            if(x.second%4 != 0){
                b = false;
            }
        }
        if(b){
            prtl("Yes");
        }else{
            prtl("No");
        }
    }else if(h%2 == 1&&w%2 == 1){
        bool b = true;
        ll c = 0, cc = 0;
        for(auto x: m){
            if(x.second%2 != 0){
                c++;
                if(c > 1){
                    b = false;
                    break;
                }
                m[x.first]--;
            }
            if(x.second % 2 == 0&&x.second%4 != 0){
                cc++;
            }else{
                continue;
            }
        }
        if(b){
            if(cc <= (h+w-2)/2&&((h+w-2)/2-cc)%2 == 0){
                b = true;
            }else{
                b = false;
            }
        }
        if(b){
            prtl("Yes");
        }else{
            prtl("No");
        }
    }else{
        bool b = true;
        ll c = 0, cc = 0;
        for(auto x: m){
            if(x.second%2 != 0){
                b = false;
                break;
            }
            if(x.second % 2 == 0&&x.second%4 != 0){
                cc++;
            }else{
                continue;
            }
        }
        //prtl(cc);
        if(b){
            ll j;
            if(h%2 == 1){
                j = w;
            }else{
                j = h;
            }
            if(cc <= j/2&&(j/2-cc)%2 == 0){
                b = true;
            }else{
                b = false;
            }
        }
        if(b){
            prtl("Yes");
        }else{
            prtl("No");
        }
    }
}

