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

char X[4] = {'S','S','W','W'};
char Y[4] = {'S','W','S','W'};

int main(){
    ll N;
    cin >> N;
    string s;
    cin >> s;
    string ss = s+s+s;
    vector<char> v(N+1);
    rep(k,4){
        bool flag = true;
        v[0] = X[k];
        v[1] = Y[k];
        rep(i,N-2){
            if((v[i+1] == 'S' && ss[N+i+1] == 'o') || (v[i+1] == 'W' && ss[N+i+1] == 'x') ){
                v[i+2] = v[i];
            }else{
                v[i+2] = ((v[i]=='S')?'W':'S');
            }
        }
        rep(i,N){
            if((ss[N+i+1] == 'o' && v[(i+1)%N] == 'S') || (v[(i+1)%N] == 'W' && ss[N+i+1] == 'x')){
                if(v[i] == v[(i+2)%N])continue;
                flag = false;
                break;
            }else{
                if(v[i] != v[(i+2)%N])continue;
                flag = false;
                break;
            }
        }
        if(flag){
            rep(j,N){
                cout << v[j];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}