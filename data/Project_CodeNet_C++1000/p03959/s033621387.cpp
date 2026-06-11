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

ll hig[100009], TK[100009], AO[100009];

bool conf[100009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    rep(i,N) cin>>TK[i];
    rep(i,N) cin>>AO[i];
    
    rep(i,N){
        hig[i]=TK[i];
        if(i==0||TK[i]>TK[i-1]){
            conf[i]=true;
        }
    }
    
    rrep(i,N-1){
        if(conf[i]){
            if(AO[i]<hig[i]){
                cout1(0);
                return 0;
            }
        }
        if(i==N-1||AO[i]>AO[i+1]){
            conf[i]=true;
            if(hig[i]<AO[i]){
                cout1(0);
                return 0;
            }
        }
        hig[i]=min(hig[i],AO[i]);
    }
    
    ll res=1;
    rep(i,N)if(!conf[i]){
        res=(res*hig[i])%MOD;
    }
    cout1(res);
}