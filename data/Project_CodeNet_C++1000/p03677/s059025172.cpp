#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define Forn(i, n) for(int i=1; i<=(n); i++)
#define forn(i, n) for(int i=0; i<(n); i++)
#define lid id<<1|1
#define rid (id<<1)+2
#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define int long long

const int MAX=1e5+5;

int N, M, ptr, ret, a[MAX];

struct Suff
{
    int tag1[MAX*4], tag2[MAX*4];
    Suff()
    {
        memset(tag1, 0, sizeof(tag1));
        memset(tag2, 0, sizeof(tag2));
    }
    inline void update(int a, int b, int k1, int b1)
    {
        if(a>=b) return;
        tag1[a]+=k1;
        tag1[b]-=k1;
        
        tag2[a]+=b1;
        tag2[b]-=b1;
    }
    inline void print(int &ret)
    {
        Forn(i, M)
        {
            tag1[i]+=tag1[i-1];
            tag2[i]+=tag2[i-1];
            ret=min(ret, tag1[i]*i+tag2[i]);
        }
    }
}S;

signed main()
{
    scanf("%lld %lld", &N, &M);
    forn(i, N)
        scanf("%lld", &a[i]);
    ptr=M+1;
    
    forn(i, N-1)
    {
        if(a[i]==a[i+1]) continue;
        if(a[i]<a[i+1])
        {
            S.update(1, a[i]+1, 0, a[i+1]-a[i]);
            S.update(a[i]+1, a[i+1]+1, -1, a[i+1]+1);
            S.update(a[i+1]+1, ptr, 0, a[i+1]-a[i]);
        }
        else
        {
            S.update(1, a[i+1]+1, -1, a[i+1]+1);
            S.update(a[i+1]+1, a[i]+1, 0, M-a[i]+a[i+1]);
            S.update(a[i]+1, ptr, -1, M+a[i+1]+1);
        }
    }
    ret=2e18;
    S.print(ret);
    printf("%lld\n", ret);
    return 0;
}