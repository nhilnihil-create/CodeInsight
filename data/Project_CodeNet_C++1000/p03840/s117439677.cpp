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

int main(){
    vll a(7);
    rep(i, 0, 7){
        cin >> a[i];
    }
    ll ans = 0;
    ll r = 0;
    bool t = true;
    if(a[0]%2 == 0){r++;}
    if(a[3]%2 == 0){r++;}
    if(a[4]%2 == 0){r++;}
    if(a[0] == 0){t = false;}
    if(a[3] == 0){t = false;}
    if(a[4] == 0){t = false;}
    if(r>1||!t){
        ans += (a[0] - a[0]%2);
        ans += (a[3] - a[3]%2);
        ans += (a[4] - a[4]%2);
    }else{
        if(a[0]%2 != 0){
            ans += (a[0] - 1);
        }else{
            ans += (a[0] - 2);
        }
        if(a[3]%2 != 0){
            ans += (a[3] - 1);
        }else{
            ans += (a[3] - 2);
        }
        if(a[4]%2 != 0){
            ans += (a[4] - 1);
        }else{
            ans += (a[4] - 2);
        }
        ans += 3;
    }
    ans += a[1];
    prtl(ans);
}