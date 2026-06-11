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
    int n,x;
    cin >> n >> x;
    if(x==1||x==2*n-1){
        puts("No");
        return 0;
    }
    vint ans(2*n-1);
    if(n==2){
        REP(i,3){
            ans[i] = i+1;
        }
    }else{
        if(x<=n){
            ans[n-1]=x;
            ans[n-3]=x+1;
            ans[n-2]=x-1;
            ans[n]=x+2;
            int now = 1;
            REP(i,n-3){
                if(now==x-1){
                    now=x+3;
                }
                ans[i]=now;
                now++;
            }
            for(int i=n+1;i<2*n-1;++i){
                if(now==x-1){
                    now=x+3;
                }
                ans[i]=now;
                now++;
            }
        }else{
            ans[n-1]=x;
            ans[n-3]=x-2;
            ans[n-2]=x+1;
            ans[n]=x-1;
            int now = 1;
            REP(i,n-3){
                ans[i]=now;
                now++;
                if(now==x-2){
                    now=x+2;
                }
            }
            for(int i=n+1;i<2*n-1;++i){
                ans[i]=now;
                now++;
                if(now==x-2){
                    now=x+2;
                }
            }
        }
        
    }
    cout << "Yes\n";
    REP(i,2*n-1){
        cout << ans[i] << "\n";
    }
    return 0;
}