#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> ans(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        ans[a]++;
        ans[b]++;
    }
    rep(i,n){
        cout<< ans[i] << endl;
    }
    return 0;
}