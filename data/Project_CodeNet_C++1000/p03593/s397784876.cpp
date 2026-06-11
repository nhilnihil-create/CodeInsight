#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

////////////////////////////////////////////////////////

ll b[30];

int main() {
    ll h, w; cin >> h >> w;
    rep(i, 0, h){
        string s; cin >> s;
        rep(j, 0, w){
            b[s[j]-'a']++;
        }
    }
    
    ll g1 = 0, g2 = 0, g4 = 0;
    
    if(h%2 != 0 && w%2 != 0){
        g1 = 1;
        g2 = h/2 + w/2;
        g4 = (h/2)*(w/2);
    }else{
        g1 = 0;
        g4 = (h/2)*(w/2);
        g2 = (h*w - g4*4)/2;
    }

    // cout << "g1 : " << g1 << endl;
    // cout << "g2 : " << g2 << endl;
    // cout << "g4 : " << g4 << endl;

    // rep(i, 0, 26) cout << b[i] << " \n"[i==24];

    if(g1){
        rep(i, 0, 26){
            if(b[i]%2 == 1){
                b[i]--;
                break;
            }
        }
    } 
    ll t = 0;
    while(g4){
        rep(i, 0, 26){
            if(b[i] >= 4){
                b[i] -= 4;
                g4--;
                if(!g4) break;
            }
        }
        t++;
        if(t >= 100000){
            co("No");
            return 0;
        }
    }
    
    // rep(i, 0, 26) cout << b[i] << " \n"[i==24];

    t = 0;
    while(g2){
        rep(i, 0, 26){
            if(b[i] && b[i]%2 == 0){
                b[i] -= 2;
                g2--;
                if(!g2) break;
            }
        }
        t++;
        if(t >= 100000){
            co("No");
            return 0;
        }
    }

    // rep(i, 0, 26) cout << b[i] << " \n"[i==24];

    bool f = true;
    rep(i, 0, 26){
        if(b[i]) f = false;
    }
    if(f) co("Yes");
    else co("No");

    return 0;
}
 
 
