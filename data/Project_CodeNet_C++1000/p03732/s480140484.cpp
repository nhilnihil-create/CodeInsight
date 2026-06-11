#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
using namespace std;
typedef long long LL;

const int N=101;
LL W[N],V[N];

int main() {
    LL n,w;
    scanf("%lld %lld", &n, &w);
    REP(i,n) scanf("%lld %lld", W+i, V+i);
    vector<LL> ws;
    map<int,vector<LL>> mp;
    REP(i,n) {
        ws.push_back(W[i]);
        mp[W[i]].push_back(V[i]);
    }
    sort(ws.begin(),ws.end());
    ws.erase(unique(ws.begin(),ws.end()),ws.end());
    for ( int i:ws ) {
        sort(mp[i].rbegin(),mp[i].rend());
        for ( int j=1; j<mp[i].size(); j++ ) {
            mp[i][j]+=mp[i][j-1];
        }
    }
    if ( ws.size()==1 ) {
        LL k=w/ws[0];
        k=min(n,k);
        if ( k==0 ) cout << 0 << '\n';
        else cout << mp[ws[0]][k-1] << '\n';
    }
    if ( ws.size()==2 ) {
        LL ans=0;
        for ( int i=0; i<=mp[ws[0]].size(); i++ ) {
            for ( int j=0; j<=mp[ws[1]].size(); j++ ) {
                if ( ws[0]*i+ws[1]*j>w ) continue;
                LL res=0;
                if ( i>0 ) res+=mp[ws[0]][i-1];
                if ( j>0 ) res+=mp[ws[1]][j-1];
                ans=max(ans,res);
            }
        }
        cout << ans << '\n';
    }
    if ( ws.size()==3 ) {
        LL ans=0;
        for ( int i=0; i<=mp[ws[0]].size(); i++ ) {
            for ( int j=0; j<=mp[ws[1]].size(); j++ ) {
                for ( int k=0; k<=mp[ws[2]].size(); k++ ) {
                    if ( ws[0]*i+ws[1]*j+ws[2]*k>w ) continue;
                    LL res=0;
                    if ( i>0 ) res+=mp[ws[0]][i-1];
                    if ( j>0 ) res+=mp[ws[1]][j-1];
                    if ( k>0 ) res+=mp[ws[2]][k-1];
                    ans=max(ans,res);
                }
            }
        }
        cout << ans << '\n';
    }
    if ( ws.size()==4 ) {
        LL ans=0;
        for ( int i=0; i<=mp[ws[0]].size(); i++ ) {
            for ( int j=0; j<=mp[ws[1]].size(); j++ ) {
                for ( int k=0; k<=mp[ws[2]].size(); k++ ) {
                    for ( int l=0; l<=mp[ws[3]].size(); l++ ) {
                        if ( ws[0]*i+ws[1]*j+ws[2]*k+ws[3]*l>w ) continue;
                        LL res=0;
                        if ( i>0 ) res+=mp[ws[0]][i-1];
                        if ( j>0 ) res+=mp[ws[1]][j-1];
                        if ( k>0 ) res+=mp[ws[2]][k-1];
                        if ( l>0 ) res+=mp[ws[3]][l-1];
                        ans=max(ans,res);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

