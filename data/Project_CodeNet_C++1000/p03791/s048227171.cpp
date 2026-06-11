#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
#define LL long long
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define lc (x<<1)
#define rc ((x<<1)|1)
const int N=100005;
const LL mod=1000000007;
LL a[N];
LL jc(LL n) {LL ans=1;for (LL i=1;i<=n;i++) ans=ans*i%mod;return ans;}
int main(){
  //  freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int i,n,t;LL j,ans=1,die=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (j=1;j<=n;){
        while (j<=n&&2*(j-die)-1<=a[j]) j++;
        if (j>n) break; 
        ans=ans*(j-die)%mod;die++;
    }
    ans=ans*jc(n-die)%mod;
    cout<<ans<<endl;
  //  system("pause");
    return 0;
}
