#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
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



int main(){
    
    int N, A,B;
    cin >> N >> A >> B;
    vector<int> X(N);
    rep(i,N) cin >> X[i];
    ll ans = 0;
    FOR(i,0,N-1) 
        ans += min((ll)(X[i+1]-X[i])*A,(ll) B);
    cout << ans;
    rn 0;
}