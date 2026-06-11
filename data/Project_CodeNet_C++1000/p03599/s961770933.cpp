#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll anss = 0, anst = (min(a,b)*100 <= f) ? min(a,b)*100 : 0;
    double cons = 0.0;
    
    for(ll i=0; i<= 30; i++){
        if(100*a*i > f) break;
        for(ll j=0; j<= 30; j++){
            if(100*a*i + 100*b*j > f) break;
            for(ll k=0;; k++){
                if(100*a*i + 100*b*j + c*k > f || (a+b)*e < c*k) break;
                for(ll l=0;; l++){
                    if(100*a*i + 100*b*j + c*k + d*l > f || (a*i+b*j)*e < c*k + d*l) break;
                    double tmp = (i == 0 && j==0 && k==0 && l== 0) ? 0.0 : (100.0*(c*k + d*l))/(100.0*a*i + 100.0*b*j + c*k + d*l);
                    if(cons < tmp){
                        cons = tmp;
                        anss = c*k + d*l;
                        anst = 100*a*i + 100*b*j + anss;
                    }
                }
            }
        }
    }
    cout << anst << " " << anss << endl;
}