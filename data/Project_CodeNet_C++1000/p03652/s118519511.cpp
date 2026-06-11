#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
//#define int long long
#define ld long double
#define vi deque<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<int,ll>
#define pll pair<ll,ll>
#define _path pair<ll,pair<ll,int> > 
#define vv deque
//#define endl '\n'
//#define mp make_pair

using namespace std;

const int MAXN = 300+5;
const int MOD = 1e9+7;


int grid[MAXN][MAXN];

int best = MAXN;
int n;
int m;

bool take[MAXN];
void recurse(){
    int cnt = 0;
    FOR(i,m)cnt += take[i];
    if(cnt == 0)return;

    int f[m];FOR(i,m)f[i] = 0;
    
    FOR(i,n){
        FOR(j,m){
            if(take[grid[i][j]]){
                f[grid[i][j]]++;
                break;
            }
        }
    }
    int x = 0;
    FOR(i,m){
        if(!take[i])continue;
        if(f[x] < f[i])x= i;
    }
    best= min(best,f[x]);
    take[x] = 0;
    recurse();

}


void solve(){
    
    cin >> n >> m;
    FOR(i,n){
        FOR(j,m){
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }
   // vi x;FOR(i,n)x.pb(i);
    FOR(i,m)take[i] = 1;
    recurse();
    cout << best << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // test(958681902);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}