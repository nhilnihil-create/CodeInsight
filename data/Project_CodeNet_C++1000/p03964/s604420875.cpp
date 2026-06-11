#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
#define v_inputrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} //配列vにn個の要素を入力する
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)

int main(){
    int n;
    cin >> n;
    vector<long double> t(n), a(n);
    rep(i, n){cin >> t.at(i) >> a.at(i);}
    ll t_tmp;
    ll a_tmp;
    t_tmp = 1;
    a_tmp = 1;
    for(ll i = 0 ; i < n ; i++){
        ll n = max(ceil(t_tmp / t.at(i)), ceil(a_tmp / a.at(i)));
        t_tmp = t.at(i) * n;
        a_tmp = a.at(i) * n;
    }

    cout << t_tmp + a_tmp;
}

