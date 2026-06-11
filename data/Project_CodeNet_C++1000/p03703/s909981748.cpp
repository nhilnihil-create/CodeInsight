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
};

int main(int argc, char* argv[])
{
    int n, K;
    scanf("%d%d", &n, &K);

    vector<int> a(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]); 
        a[i]-=K;
    }
    
    vector<ll> s(n+1);
    for(i=0; i<n; i++) {
        s[i+1]=s[i]+a[i];
    }

    map<ll,int> z;
    for(i=0; i<=n; i++) {
        z[s[i]]=0;
    }
    int cnt=0;
    auto it=z.begin();
    for(; it!=z.end(); ++it) {
        cnt++;
        it->second=cnt;
    }

    ll ans=0;
    BIT<int> bit(cnt);
    for(i=0; i<=n; i++) {
        ans += bit.sum(z[s[i]]);
        bit.add(z[s[i]],1);
    }
    printf("%lld\n", ans);

    return 0;
}
