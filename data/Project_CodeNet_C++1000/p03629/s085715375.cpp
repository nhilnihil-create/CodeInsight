#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int nxt[200009][26], n[26], len[200009], chr[200009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin>>s;
    int N=s.size();
    
    rep(i,26) n[i]=N+1;
    rrep(i,N){
        len[i]=INF;
        rep(j,26){
            nxt[i][j]=n[j];
            if(len[i]>len[n[j]]){
                len[i]=len[n[j]];
                chr[i]=j;
            }
        }
        len[i]++;
        if(i) n[s[i-1]-'a']=i;
    }
    
    string ans;
    int cur=0;
    while(cur<N+1){
        ans+='a'+chr[cur];
        cur=nxt[cur][chr[cur]];
    }
    cout1(ans)
}