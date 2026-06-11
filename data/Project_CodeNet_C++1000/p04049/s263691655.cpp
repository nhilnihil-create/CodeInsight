//
//  main.cpp
//  CP
//
//  Created by Shiv Pavan Raj on 22/02/20.
//  Copyright © 2020 Shiv Pavan Raj. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define M 1000000007
#define MM 998244353
#define SZ(a) int((a).size())

using ll = long long;
using VI = vector<int>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using VLL = vector<ll>;
using ld = long double;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}
const int MX = 2e5+10;
const int MX2 = 1e6+5;

ll INF= 4 * (ll)1e18;
int mx = 2 * (ll)1e9 + 10;

struct node {
    int to;
    int next;
}edge[MX];
int head[MX];
int cnt,mxx,ans;
void add(int x,int y) {
    edge[cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
void dfs(int v,int par,int step) {
    mxx++;
    if (step == 0) return ;
    for (int i = head[v] ; ~i; i = edge[i].next) {
        if (edge[i].to == par) continue;
        dfs(edge[i].to,v,step-1);
    }
}
int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); // insert code here...
    int n,k;
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) head[i] = -1;
    for (int i = 0; i < n -1; i++) {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    ans=0;
    if (k%2) {
        for (int i = 1;i <= n; i++) {
            for (int j= head[i]; ~j; j = edge[j].next) {
                mxx = 0;
                int t = edge[j].to;
                dfs(t,i,k/2);
                dfs(i,t,k/2);
                ans = max(ans,mxx);
            }
        }
    }
    else {
        for (int i = 1; i <= n;i++) {
            mxx = 0;
            dfs(i,0,k/2);
            ans = max(ans,mxx);
        }
    }
    cout << n - ans << endl;
    return 0;
}
