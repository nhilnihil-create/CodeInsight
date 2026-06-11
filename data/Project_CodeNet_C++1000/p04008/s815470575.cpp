#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<ll>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vecbl vector<bool>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
string stin(){string s;cin>>s;return s;}

vec par,height,ran;
vector<vec> chi,cir;
int k,ans=0;
int func(int v){
    int res = 0;
    REP(e,chi[v]){
        int x=func(e);
        if((v==0 && x==k+1) || (v>0 && x==k)){
            ans++;
        }else{
            res = max(res,x);
        }
    }
    return res+1;
}

int main(){
    int n=in();
    k=in();
    chi.resize(n);
    par.resize(n);
    height.resize(n);
    ran.resize(n);
    rep(i,n){
        int x=in()-1;
        if(i==0){
            if(x!=0)ans++;
            par[0]=-1;
        }else{
            chi[x].pb((int)i);
            par[i]=x;
        }
    }
    func(0);
    cout<<ans<<endl;
}
