#include <stdio.h>
#include <algorithm>
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
#include <cstdio>
#include <list>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define vec vector<int>
#define vecll vector<ll>
#define vecstr vector<string>
#define vecch vector<char>
#define vecpii vector<pii>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
using namespace std;
int in(){int x;scanf("%d",&x);return x;}
string stin(){string s;cin>>s;return s;}
ll lin(){ll x;scanf("%lld",&x);return x;}

int main(){
    int n=in(),k=in();
    vecll s1(n+1),s2(n+1);
    s1[0]=s2[0]=0;
    rep(i,n){
        int x=in();
        s1[i+1]=s1[i]+x;
        s2[i+1]=max(0,x)+s2[i];
    }
    ll ans=0;
    rep(i,n-k+1)ans=max(ans,s2[n]-s2[i+k]+s2[i]+max(s1[i+k]-s1[i],0ll));
    cout<<ans<<endl;
}