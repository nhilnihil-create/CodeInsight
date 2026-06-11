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

int main(int argc, char* argv[])
{
    int n,m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > z(m+1);   // length, l
    int i;
    for(i=0; i<n; i++) {
        int l,r;
        scanf("%d%d", &l, &r);
        z[r-l+1].push_back(l);
    }

    vector<int> ans(m+1);
    BIT<int> bit(m);

    for(i=1; i<=m; i++) {
        int siz=z[i].size();
        int k;
        for(k=0; k<siz; k++) {
            int l=z[i][k], r=l+i-1;
            bit.add(l, 1);
            bit.add(r+1, -1);
        }

        for(k=i; k<=m; k+=i) {
            ans[i]+=bit.sum(k);
        }
    }

    int sum=n;
    for(i=1; i<=m; i++) {
        sum-=(int)z[i].size();
        ans[i]+=sum;
    }

    for(i=1; i<=m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
