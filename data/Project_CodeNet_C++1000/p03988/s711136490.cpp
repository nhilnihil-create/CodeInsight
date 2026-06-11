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

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    vi a(n);
    map<int,int> cnt;
    for (auto& i:a){
        cin>>i;
        cnt[i]++;
    }
    int MAX=*max_element(all(a));
    for (int i=0;i<=MAX;i++){
        if (cnt[max(i,MAX-i)]==0){
            cout<<"Impossible"<<"\n";
            return 0;
        }
        cnt[max(i,MAX-i)]--;
    }
    a.clear();
    for (auto i:cnt){
        for (int j=0;j<i.sec;j++){
            a.pb(i.fir);
        }
    }
    if (!a.empty()&&*min_element(all(a))<(MAX+1)/2+1){
        cout<<"Impossible"<<"\n";
        return 0;
    }
    cout<<"Possible"<<"\n";
    return 0;
}
