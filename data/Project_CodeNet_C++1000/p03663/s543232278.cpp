#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

string ans = "";
bool f(ll a){
    cout<<"? "<<ans<<a;
    rep(i, 15 - to_string(a).size() - ans.size()) cout<<9;
    cout<<endl;
    char c;
    cin>>c;
    return c == 'Y';
}
bool f2(ll a){
    cout<<"? "<<a<<endl;
    char c;
    cin>>c;
    return c == 'Y';
}

int main() {
    while(ans.size() < 9){
        int lb = -1, ub = 9;
        while(ub - lb > 1){
            int cen = (ub + lb) / 2;
            if(ans.empty() && cen == 0){
                if(f2(1e+16)) {
                    ll temp = 9, re = 1;
                    while (!f2(temp)) {
                        re *= 10;
                        temp *= 10;
                        temp += 9;
                    }
                    cout <<"! "<< re << endl;
                    return 0;
                }else{
                    break;
                }
            }
            (f(cen) ? ub : lb) = cen;
        }
        ans.push_back(char('0' + ub));
    }
    ll temp = 10, re = 1;
    while (f2(temp)) {
        ++re;
        temp *= 10;
    }
    cout<<"! "<<ans.substr(0, re)<<endl;
}