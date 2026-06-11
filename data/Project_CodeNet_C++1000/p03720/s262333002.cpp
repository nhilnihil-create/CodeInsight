#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), c(n);
    rep(i,n) c[i] = 0;
    rep(i,m){
        cin >> a[i] >> b[i];
        c[a[i]-1]++; c[b[i]-1]++;
    }
    rep(i,n) cout << c[i] << endl;

    return 0;
}