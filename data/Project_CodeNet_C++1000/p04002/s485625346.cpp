//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

#ifdef __APPLE__
    # include <iostream>
    # include <cmath>
    # include <algorithm>
    # include <stdio.h>
    # include <cstdint>
    # include <cstring>
    # include <string>
    # include <cstdlib>
    # include <vector>
    # include <bitset>
    # include <map>
    # include <queue>
    # include <ctime>
    # include <stack>
    # include <set>
    # include <list>
    # include <random>
    # include <deque>
    # include <functional>
    # include <iomanip>
    # include <sstream>
    # include <fstream>
    # include <complex>
    # include <numeric>
    # include <immintrin.h>
    # include <cassert>
    # include <array>
    # include <tuple>
    # include <unordered_map>
    # include <unordered_set>
    # include <thread>
#else
    # include <bits/stdc++.h>
#endif

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

int h,w,n;

bool is_ok_start(int a,int b)
{
    return a>=1&&b>=1&&a+2<=h&&b+2<=w;
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>h>>w>>n;

    vector<pii> black;
    vector<pii> interesting;
    for (int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        black.pb(mp(a,b));
        for (int dx=0;dx>=-2;dx--){
            for (int dy=0;dy>=-2;dy--){
                if (is_ok_start(a+dx,b+dy)){
                    interesting.pb(mp(a+dx,b+dy));
                }
            }
        }
    }
    sort(all(black));
    sort(all(interesting));
    interesting.resize(unique(all(interesting))-interesting.begin());

    vi ans(10);
    for (auto i:interesting){
        int cur=0;
        for (int dx=0;dx<=2;dx++){
            for (int dy=0;dy<=2;dy++){
                cur+=(binary_search(all(black), mp(i.fir+dx,i.sec+dy)));
            }
        }
        ans[cur]++;
    }
    ans[0]+=(w-2)*(h-2)-len(interesting);

    for (auto i:ans){
        cout<<i<<"\n";
    }
}
