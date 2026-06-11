//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vint d(n,0);
    vint a(n);
    vvint cld(n);
    a[0]=-1;
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i]--;
        cld[a[i]].pb(i);
    }
    
    vint cn(n,0);
    queue<int> q;
    REP(i,n){
        cn[i]=(int)cld[i].size();
        d[i] = (int)cld[i].size();
        if(cn[i]==0){
            q.push(i);
        }
    }
    vvint cd(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        sort(rALL(cd[now]));
        REP(i,(int)cld[now].size()){
            d[now] = max(d[now], cd[now][i]+i+1);
        }
        int p = a[now];
        if(p==-1) break;
        cd[p].pb(d[now]);
        cn[p]--;
        if(cn[p]==0) q.push(p);
    }
    cout << d[0] << endl;
    return 0;
}