#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

// main starts here

int main(){
    string s; cin >> s;
    ll ss = s.size();
    ll ans = ss * (ss-1) /2;
    vector<ll> cnt(26,0);
    rep(i,ss){
        cnt.at((int)(s.at(i)-'a'))++;
    }
    rep(i,26){
        ans -= (cnt.at(i)*(cnt.at(i)-1)/2);
    }
    cout << ans + 1 << endl;    
}
