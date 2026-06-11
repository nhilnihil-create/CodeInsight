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
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    map<char, int> mp;
    rep(i, h)cin >> s[i];
    rep(i, h){
        rep(j, w){
            mp[s[i][j]]++;
        }
    }

    ll g1 = 0, g2 = 0, g4;
    if(h * w % 2 == 1)g1 = 1;
    if(h % 2 == 1)g2 += w / 2;
    if(w % 2 == 1)g2 += h / 2;
    g4 = (h / 2) * (w / 2);
    ll cnt = 0;
    bool f = true;
    //両方偶数
    map<int, int> c;
    if(h % 2 == 0 && w % 2 == 0){
        for(auto m : mp){
            if(m.second % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    //両方奇数
    if(h % 2 && w % 2){
        for(auto m : mp)c[m.second % 4]++;
        if(c[3] == 1){
            c[2]++;
            c[1]++;
        }
        if(c[1] != 1)f = false;
        if(c[2] > h / 2 + w / 2)f = false;
        cout << (f ? "Yes" : "No") << endl;
        return 0;
    }
    if(w % 2 == 0)swap(h, w);
    for(auto m : mp)c[m.second % 4]++;
    if(c[1] > 0 || c[3] > 0)f = false;
    if(c[2] > g2)f = false;
    cout << (f ? "Yes" : "No") << endl;
}



