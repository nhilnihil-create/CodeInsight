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
    int h,w,n;
    cin >> w >> h >> n;
    int l=0,r=w,u=h,d=0;
    REP(i,n){
        int x,y,a;
        cin >> x >> y >> a;
        if(a==1){
            l = max(l,x);
        }else if(a==2){
            r = min(r,x);
        }else if(a==3){
            d = max(d,y);
        }else if(a==4){
            u = min(u,y);
        }
    }
    cout << max(0,r-l) * max(0,u-d) << endl;

    return 0;
}