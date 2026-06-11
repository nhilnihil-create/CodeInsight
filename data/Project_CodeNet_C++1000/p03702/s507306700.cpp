//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
ll n,a,b;
const int nmax = 100000;
vll h(nmax);
bool enough(ll t){
    ll ab = 0;
    REP(i,n){
        ll hp = h[i];
        hp -= t*b;
        if(hp>0){
            ab+=(hp-1)/(a-b)+1;
        }
    }
    bool ret = true;
    if(ab>t){
        ret = false;
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    //vll h(n);
    ll sum = 0;
    REP(i,n){
        ll tmp;
        cin >> tmp;
        h[i]=tmp;
        sum+=h[i];
    }
    ll ok = (sum-1)/b+1;
    ll ng = -1;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(enough(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}