#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>


     
#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define pb push_back
#define sz size()
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

     
const ll MOD = 1e9 + 7;
const ll ZER = 0;

ll f(ll n){
    ll sum = 0;
    for(ll i = 1; i <= n; i *= 2){
        //i桁目の1の個数
        ll now = n / (2 * i) * i + max(ZER, n % (i * 2) - i);
        now %= 2;
        sum += now * i;
        //cout << now << " " << i << endl;
    }
    return sum;
}

int main(){
    string s;
    ll k;
    cin >> s >> k;
    vector<ll> a(s.sz);
    rep(i, s.sz){
        a[i] = 'z' - s[i] + 1;
        a[i] %= 26;
    }
    rep(i, s.sz){
        if(a[i] <= k){
            k -= a[i];
            s[i] = 'a';
        }
    }
    k %= 26;
    s[s.sz - 1] = (char)('a' + ((s[s.sz - 1] - 'a') + k) % 26);
    cout << s << endl;
}



