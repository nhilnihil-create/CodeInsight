#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

string str[4] = {"dream", "dreamer", "erase", "eraser"};

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    reverse(S.begin(), S.end());
    rep(i,4){
        reverse(str[i].begin(), str[i].end());
    }
    rep(i,N){
        bool flag = 0;
        rep(j,4){
            if(str[j] == S.substr(i,str[j].size())){
                i += str[j].size()-1;
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout << "NO" <<endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}