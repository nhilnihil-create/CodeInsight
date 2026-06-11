#include <iostream> 
#include <algorithm> 
#include <cstring> 
#include <cstdio>
#include <vector> 
#include <queue> 
#include <cstdlib> 
#include <iomanip>
#include <cmath> 
#include <ctime> 
#include <map> 
#include <set> 
using namespace std; 
#define lowbit(x) (x&(-x)) 
#define max(x,y) (x>y?x:y) 
#define min(x,y) (x<y?x:y) 
#define MAX 100000000000000000 
#define MOD 1000000007
#define pi acos(-1.0) 
#define ei exp(1) 
#define PI 3.141592653589793238462
#define ios() ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f3f 
#define mem(a) (memset(a,0,sizeof(a))) 
typedef long long ll;
ll n;
ll a[55];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=50;i++)
    {
        a[i]=n/50+i-1;
    }
    n%=50;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=50;j++)
        {
            a[j]--;
        }
        a[i]+=51;
    }
    printf("50\n");
    for(int i=1;i<=50;i++)
    {
        if(i!=1) printf(" ");
        printf("%lld",a[i]);
    }
    printf("\n");
    return 0;
}