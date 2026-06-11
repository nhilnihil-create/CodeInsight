#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
#define lson k<<1
#define rson k<<1|1

using namespace std;
typedef long long ll;
typedef double db;

const int INFI = 1000000000;
const int N = 100005;
const ll MOD = 1000000007;
int a[N];

int main()
{
    int n;
    while(scanf("%d",&n)+1)
    {
        a[0]=-10;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ll res(1),sum(1);
        for(int i=2;i<=n;i++)
        {
            if(a[i]<=sum*2-1||a[i-1]<sum*2-1) {}
            else ++sum;
            res = res*sum%MOD;
//            printf("%d  %d %lld\n",i,a[i],sum);
        }
        cout<<res<<endl;
    }
    return 0;
}
