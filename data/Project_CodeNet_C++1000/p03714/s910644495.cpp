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
    ll n;
    cin >> n;
    ll n3 = n*3;
    vll a(n3);
    REP(i,n3){
        cin >> a[i];
    }
    vll mae(n+1);
    priority_queue<ll,vector<ll>, greater<ll> > pq1;
    REP(i,n){
        mae[0]+=a[i];
        pq1.push(a[i]);
    }
    REP(i,n){
        ll now = pq1.top();
        if(a[n+i]<=now){
            mae[i+1]=mae[i];
        }else{
            pq1.pop();
            pq1.push(a[n+i]);
            mae[i+1]=mae[i]+a[n+i]-now;
        }
    }
    vll usi(n+1);
    priority_queue<ll> pq2;
    REP(i,n){
        usi[0]+=a[n3-1-i];
        pq2.push(a[n3-1-i]);
    }
    REP(i,n){
        ll now = pq2.top();
        if(a[n*2-1-i]>=now){
            usi[i+1]=usi[i];
        }else{
            pq2.pop();
            pq2.push(a[n*2-1-i]);
            usi[i+1]=usi[i]+a[n*2-1-i]-now;
        }
    }
    ll ans = mae[0]-usi[n];
    for(int i=1;i<=n;i++){
        ans = max(ans,mae[i]-usi[n-i]);
    }
    cout << ans << endl;

    return 0;
}