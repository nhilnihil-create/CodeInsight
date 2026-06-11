#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
vector<vector<int> > g;
int ans = 0;
int n,k;
vector<int> a;
int dfs(int id){
    int mx = 1;
    for(int x:g[id]){
        if(x!=0)mx = max(mx,dfs(x)+1);
    }
    if(id==0)return 0;
    if((mx==k&&a[id]!=0)||mx>k){
        //cerr << id << " " << mx << endl;
        ans++;
        mx =0;
    }
    return mx;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    g.resize(n);
    rep(i,n){
        cin >> a[i];
        if(i==0&&a[i]!=1){
            a[i] = 1;
            ans++;
        }
        a[i]--;
        g[a[i]].push_back(i);
    }
    
    dfs(0);
    cout << ans << endl;
    return 0;
}