#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    int n; cin >> n;
    int a[100001],v[100001];
    int Max = -1;
    rep(i,n) cin >> a[i];

    memset(v,0,sizeof(v));
    rep(i,n){
        v[a[i]+1] ++;
        if(a[i] != 0) v[a[i]-1] ++;
        v[a[i]] ++;
    }

    rep(i,100001){
        Max = max(Max,v[i]);
    }

    cout << Max;

    return 0;
}









