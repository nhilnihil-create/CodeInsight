#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};


const int MAX = 510000;
const int MOD = 1000000007;

class UnionFind {
public:
    std::vector<int> RANK;
    std::vector<int> par;

public:
    UnionFind(int n)
    {
        RANK.resize(n);
        par.resize(n);
        for(int i = 0; i < n; ++i) par[i] = i;
    }

    int FindRoot(int x)
    {
        if (par[x] == x) return x;
        par[x] = FindRoot(par[x]);
        return par[x];
    }

    bool IsSame(int x, int y)
    {
        return FindRoot(x) == FindRoot(y);
    }

    void Union(int x, int y)
    {
        x = FindRoot(x);
        y = FindRoot(y);
        if (x == y) return;
        else{
            if(RANK[x] > RANK[y]){
                par[y] = x;
            }
            else{
                par[x] = y;
                if(RANK[x] == RANK[y]){
                    RANK[x]++;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    ll h, w; cin >> h >> w;
    if(h%3==0 || w%3==0){cout<<0<<endl;return 0;}

    ll ans = 10000000009;
    for(ll i = 1; i < h; ++i)
    {
        ll s1 = i * w;
        ll s2 = (h-i) * (w / 2);
        ll s3 = h*w - s1 - s2;
        ll L = max(s1,max(s2,s3));
        ll M = min(s1,min(s2,s3));
        ans = min(ans,L-M);
    }

    for(ll i = 1; i < w; ++i)
    {
        ll s1 = i * h;
        ll s2 = (w-i) * (h / 2);
        ll s3 = h*w - s1 - s2;
        ll L = max(s1,max(s2,s3));
        ll M = min(s1,min(s2,s3));
        ans = min(ans,L-M);
    }

    for(ll i = 1; i < w; ++i)
    {
        ll s1 = i * h;
        ll s2 = ((w-i) /2) * h;
        ll s3 = h*w - s1 - s2;
        ll L = max(s1,max(s2,s3));
        ll M = min(s1,min(s2,s3));
        ans = min(ans,L-M);
    }

    for(ll i = 1; i < h; ++i)
    {
        ll s1 = i * w;
        ll s2 = ((h-i)/2) * w;
        ll s3 = h*w - s1 - s2;
        ll L = max(s1,max(s2,s3));
        ll M = min(s1,min(s2,s3));
        ans = min(ans,L-M);
    }
    cout << ans << endl;
}