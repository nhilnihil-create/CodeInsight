#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e5 + 5;
const int M=1e5 + 5;

vector <int> v[N];
bool vis[N]; 
int clr[N];
bool ok = true;
ll sz=0,bps=0,ups=0;

void dfs(int s, int c)
{
    vis[s]=true;
    sz++;
    clr[s]=c;
    for(int i=0;i<v[s].size();i++){
        int x = v[s][i];
        if(!vis[x]){
            dfs(x,(c+1)%2);
        }
        else{
            if(clr[s]==clr[x]) ok = false;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } 
    ll lone=0,bp=0,ubp=0;
    for(i=1;i<=n;i++){
        vis[i]=false;
        clr[i]=-1;
    }
    for(i=1;i<=n;i++){
        if(v[i].size() == 0) lone++;
    }

    for(i=1;i<=n;i++){
        if(v[i].size() == 0) continue;
        if(!vis[i]){
            ok=true;
            dfs(i,0);
            if(ok){
                bp++;
                bps+=sz;
                sz=0;
            }
            else{
                ubp++;
                ups+=sz;
                sz=0;
            }
        }
    }
    ll ans = 0;
    ans += bp*(2*bp + ubp) + lone*bps;
    ans += ubp*(ubp + bp) + lone*ups;
    ans += lone*(n);
    cout << ans << endl;
 
    return 0;
}