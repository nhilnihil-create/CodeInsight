#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;

int main() {
    ll n,m,r;
    cin >> n >> m >> r;
    vector<ll> rl(r);
    for(auto &rrl:rl) cin>>rrl;
    vector<vector<int>> rg(n,vector<int>(n,999999999));
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin >>a>>b>>c;
        rg[a-1][b-1] = c;
        rg[b-1][a-1] = c;
    }
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) rg[i][j]=min(rg[i][j],rg[i][k]+rg[k][j]);
    vector<int> v(r);
    iota(v.begin(), v.end(), 0);
    ll gmin = 999999999;
    do {
        ll g=0;
        for (int i=0;i<v.size()-1;i++) g+=rg[rl[v[i]]-1][rl[v[i+1]]-1];
        gmin = min(gmin,g);
    } while( next_permutation(v.begin(), v.end()));
    cout << gmin << endl;
    return 0;
}