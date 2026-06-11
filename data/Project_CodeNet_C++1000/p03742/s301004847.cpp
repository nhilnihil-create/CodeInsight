#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
#define lson l,m
#define rson m+1,r
#define pii pair<LL,int>
using namespace std;
const double pi = 2*acos(0.0);
const int maxn = 1e5+10;
const int inf=2e9;
const int maxm = 1e4 + 10;
const int mod = 998244353;



int main()
{
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif
    LL a,b;
    cin >> a >>b;
    if(abs(a-b)<=1) printf("Brown\n");
    else printf("Alice\n");
    return 0;
}
