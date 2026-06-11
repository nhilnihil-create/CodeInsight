#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int W,H;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>W>>H;
    vector<pii> vec;
    rep(i,W){
        int x;cin>>x;
        vec.push_back({x,0});
    }
    rep(i,H){
        int x;cin>>x;
        vec.push_back({x,1});
    }
    sort(all(vec));
    
    W++,H++;
    ll sum=0;
    rep(i,vec.size()){
        if(vec[i].second){
            sum+=1ll*vec[i].first*W;
            H--;
        }else{
            sum+=1ll*vec[i].first*H;
            W--;
        }
    }
    cout1(sum)
}