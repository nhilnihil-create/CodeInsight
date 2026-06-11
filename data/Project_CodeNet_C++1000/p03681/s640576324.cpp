#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator 
int MOD = 1e9+7;
void solve() {
    int a,b;
    cin>>a>>b;
    ll res=1;
    if(a>b) swap(a,b);
    if(a==b) {
        for(int i=1;i<=a;i++) res = res*i % MOD;
        res = res*res %MOD;
        res = res*2 %MOD;
    } else if(a==b-1) {
        for(int i=1;i<=a;i++) res = res*i %MOD;
        res = res*res %MOD;
        res = res*b %MOD;
    } else res=0;
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}