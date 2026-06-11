#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll N;
string s;
vector<char> t(100010,'a');

void solve(){
    REP(i,1,N-1){
        if((s[i] == 'o' && t[i] == 'S') || (s[i] == 'x' && t[i] == 'W' )){
            t[(i+1)] = t[(i-1)];
        }else{
            t[(i+1)] = ((t[(i-1)] == 'S')?'W':'S');
        }
    }
    /*
    if((s[N-1] == 'o' && t[N-1] == 'S') || (s[N-1] == 'x' && t[N-1] == 'W' )){
        if(t[N-2] == t[0]){
            if((s[0] == 'o' && t[0] == 'S') || (s[0] == 'x' && t[0] == 'W' )){
                return (t[N-1] == t[1]);
            }else{
                return (t[N-1] != t[1]);
            }
        }
    }else{
        return (t[N-2] != t[0]);
    }
    */
}

bool check(){
    REP(i,1,N+1){
        if((s[i%N] == 'o' && t[i%N] == 'S') || (s[i%N] == 'x' && t[i%N] == 'W' )){
            if(t[(i+1)%N] == t[(i-1)%N]){
                continue;
            }else{
                return false;
            }
        }else{
            if(t[(i+1)%N] == ((t[(i-1)%N] == 'S')?'W':'S')){
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
}

char x[4] = {'S','S','W','W'};
char y[4] = {'S','W','S','W'};

int main(){
    cin >> N;
    cin >> s;
    rep(i,4){
        t[0] = x[i];
        t[1] = y[i];
        solve();
        if(check()){
            rep(i,N){
                cout << t[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}