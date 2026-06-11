#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;


template<class T> class BIT   // 1-indexed (0 is not used)
{
private:
    int num;
    vector<T> bit;
public:
    BIT(int n):bit(vector<T>(n+1, 0)), num(n) {}

    T sum(int i) {   // sum of 1..i
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, T x) {
        if (i > num) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }

    int lower_bound(T x) {
        T res=0;
        int N=1;
        while(N<num) N*=2;
        int i;
        for(i=N/2; i>0; i/=2) {
            if(res+i<num && bit[res+i]<x) {
                x = x - bit[res +i];
                res = res + i;
            }
        }
        return res + 1;
    }
};

ll calc( int n, ll* a )
{
    map<ll,int> mp;
    int i;
    for(i=0; i<n; i++) {
        mp[a[i]]=0;
    }
    int num=0;
    auto it=mp.begin();
    for(; it!=mp.end(); ++it) {
        num++;
        it->second=num;
    }

    ll ans=0;
    BIT<int> bit(num);
    for(i=0; i<n; i++) {
        ans += bit.sum(mp[a[i]]);
        bit.add(mp[a[i]], 1);
    }
    return ans;
}

int main(int argc, char* argv[])
{
    int n,K;
    scanf("%d%d", &n, &K);
    vector<ll> a(n),s(n+1);
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        a[i]-=K;
        s[i+1]=s[i]+a[i];
    }

    ll ans = calc( n+1, &s[0] );
    printf("%lld\n", ans);

    return 0;
}

