#include <bits/stdc++.h>
using namespace std;

#define MAX_N 5003

int n ,k;
int a[MAX_N];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a ,a+n);
    n = lower_bound(a ,a+n ,k)-a;

    int ans = n;
    bitset <MAX_N> bs[n+1]; bs[n][0] = 1;
    for(int i=n-1; ~i; i--)
        bs[i] = bs[i+1]|(bs[i+1]<<a[i]);
    bitset <MAX_N> pref; pref[0] = 1;
    for(int i=0; i<n; i++){
        auto&suff = bs[i+1];
        for(int l=k-1 ,j=0; j<k; j++) if(suff[j]){
            for(l = min(l ,k-j-1); l >= max(0 ,k-a[i]-j); l--)
                if(pref[l]){
                    ans--;
                    goto NECC;
                }
        }

        NECC:
        pref |= (pref<<a[i]);
    }

    printf("%d\n",ans);
}
