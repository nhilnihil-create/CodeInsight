#include<bits/stdc++.h>
using ll = int_fast64_t;

int main(){
        int n, k;
        scanf("%d %d", &n, &k);
        ll a[n];
        for(int i=0; i<n; i++) scanf("%ld", &a[i]);

        ll ans = 1e18;
        for(int i=0; i<(1<<n); i++){
                if(__builtin_popcount(i)<k) continue;

                ll cnt = 0, wall = 0;
                for(int j=0; j<n; j++){
                        if((i>>j)&1){
                                if(wall>=a[j]){
                                        cnt += wall-a[j]+1;
                                        wall++;
                                }
                        }
                        wall = std::max(wall, a[j]);
                }

                ans = std::min(ans, cnt);
        }

        printf("%ld\n", ans);
        return 0;
}