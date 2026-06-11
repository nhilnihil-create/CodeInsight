#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define rn return
#define fi first
#define se second
typedef std::pair<int,int> P;
using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main(){
    int N,M;
    cin >> N >> M;
    
    const int NMAX = 1000;
    const int MMAX = 2000;
    int a[MMAX], b[MMAX];
    ll c[MMAX];
    
    rep(i,M){
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i]; a[i]--; b[i]--;
    }
    
    ll dist[NMAX];
    rep(i,N){
        dist[i] = INF;
    }
    
    dist[0] = 0LL;
    
    rep(loop,N-1){
        rep(i,M){
            if (dist[a[i]]==INF) continue;
            if (dist[b[i]]>dist[a[i]]+c[i]){
                dist[b[i]] = dist[a[i]] + c[i];
            }
        }
    }
    ll ans = dist[N-1];
    
    bool negative[NMAX];
    rep(i,N){
        negative[i] = false;
    }
    
    rep(loo,N-1){
        rep(i,M){
            if (dist[a[i]] == INF) continue;
            if(dist[b[i]]>dist[a[i]]+c[i]){
                dist[b[i]] = dist[a[i]]+c[i];
                negative[b[i]] = true;
            }
            if (negative[a[i]]==true){
                negative[b[i]] = true;
            }
        }
    }
    
    if (negative[N-1])
        cout << "inf";
    else
        cout << -ans;
    rn 0;
}
