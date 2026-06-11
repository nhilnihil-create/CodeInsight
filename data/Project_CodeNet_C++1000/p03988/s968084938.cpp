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
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N;
int nums[109];
map<int,int> dic;
int mx=0,mn=INF;

void pr(int ans){
    cout1((ans?"Possible":"Impossible"))
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    rep(i,N){
        int x; cin>>x;
        dic[x]++;
        nums[i]=x;
        chmax(mx,x);
        chmin(mn,x);
    }
    
    sort(nums,nums+N);
    rep1(i,N-1) if(nums[i]-nums[i-1]>1) pr(0);
    
    if(mx%2==0){
        if(mn!=mx/2) pr(0);
        if(dic[mn]!=1) pr(0);
        else dic[mn]++;
    }else{
        if(mn!=mx/2+1) pr(0);
        if(dic[mn]!=2) pr(0);
    }
    
    for(auto d:dic){
        if(d.second<=1) pr(0);
    }
    
    pr(1);
}