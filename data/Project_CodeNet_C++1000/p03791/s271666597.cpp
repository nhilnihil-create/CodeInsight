#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 1e5+10;
const int MOD = 1e9 + 7;
const int M = 1e9+10;

long long a[maxn];

void init()
{
    a[0]=1;
    for(int i=1;i<=maxn;i++){
         a[i]=(a[i-1]*i)%MOD;
    }
}
int n;
int pos[maxn];
int main()
{
  //  freopen("acm.txt","r",stdin);
    init();
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%d",&pos[i]);
        int k=1;
        int cnt = 0;
        long long ans = 1;
        for(int i=0;i<n;i++){
          //  cout << "cnt: " << cnt<<" " << "k: " << k <<" " << pos[i] << endl;
            if(k <= pos[i] && i!=n-1){
                k+=2;
                cnt++;
            }else if(k <= pos[i] && i==n-1){
                ans = ans * a[cnt + 1] % MOD;
              //  cout << "ans1: " << ans <<  endl;
            }else if(i!=n-1){
                ans = ans * (cnt + 1) % MOD;
             //   cout << "ans2: " << ans <<  endl;
            }else{
                ans = (ans * a[cnt+1] ) % MOD;
              //   cout << "ans3: " << ans <<  endl;
            }
        }
        printf("%I64d\n",ans);
    }
}