//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vint a(n);
    REP(i,n) cin >> a[i];
    sort(ALL(a));
    if(a[n-1]-a[0]>1){
        cout << "No" << endl;
        return 0;
    }
    int x=0, y=0;
    REP(i,n){
        if(a[i]==a[0]){
            x++;
        }else{
            y++;
        }
    }
    //cout << x << " " << y << endl;
    if(x==1){
        if(y>=2*a[0]){
            cout << "Yes" << endl;
            return 0;
        }
    }else{
        if(y==0){
            if(n>=a[0]*2||a[0]==n-1){
                cout << "Yes" << endl;
                return 0;
            }
        }else if(y>=2){
            if(y>=(a[0]-x+1)*2&&a[0]-x+1>=1){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}