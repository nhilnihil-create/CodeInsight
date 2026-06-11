#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{   
    //0 01 10 11
    string s;
    cin >> s;
    int n = s.size(); --n;
    
    ll ans = 0;
    rep(bit, 1<<n) {
        ll t = (s[0]-'0');
        rep(i, n) {
            if(bit & (1<<i)) {
                ans += t;
                t = 0;
            }
            t *= 10;
            t += (s[i+1]-'0');
            //cout << t << endl;
        }
        ans += t;
        //cout << endl;
    } 

    cout << ans << endl;

    return 0;
}
