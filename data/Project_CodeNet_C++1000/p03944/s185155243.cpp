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

//最大公約数
ll gcd(ll a, ll b){
    if(a % b == 0)return b;
    else return gcd(b, a % b);
}

int main(){
    ll w, h, n;
    cin >> w >> h >> n;
    ll mah = h, mih = 0, maw = w, miw = 0;
    rep(i, n){
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1)chmax(miw, x);
        if(a == 2)chmin(maw, x);
        if(a == 3)chmax(mih, y);
        if(a == 4)chmin(mah, y);
    }
    if(maw - miw < 0 || mah - mih < 0){
        cout << 0 << endl;
        return 0;
    }
    cout << max(ZER, (maw - miw) * (mah - mih)) << endl;
}



