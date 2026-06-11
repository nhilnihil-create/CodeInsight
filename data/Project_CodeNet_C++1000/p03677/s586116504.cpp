#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
#define LL long long
LL ans, now;
int n, m;
LL tag[N], add, tong[N], a[N], cha[N];
int main(){
    //freopen("arc077e.in", "r", stdin);
    //freopen("arc077e.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i <= n; i++){
        scanf("%lld", &a[i]);
        if(i > 1){
            cha[i] = a[i] - a[i-1] + (a[i] - a[i-1] < 0 ? m : 0);
            ans += cha[i];
            if(cha[i] == 1)continue;
            int x = a[i] + 2 - cha[i];
            int y = a[i] + 1;
            if(y > m)y = 1;
            if(x <= 0)x += m;
            if(a[i] < cha[i] - 1){
                tag[1]--;
                tong[1] += a[i] - cha[i];
                if(y > 1){
                    tong[y] += cha[i];
                    tag[y]++;
                }
                tong[x]--;
                tag[x]--;
            }
            else{
                tong[x]--;
                tag[x]--;
                if(y > x)tong[y] += cha[i], tag[y]++;
            }
            //printf("i=%d cha=%d x=%d y=%d\n", i, cha[i], x, y);
        }
    }
    now = ans;
    for(int i = 1;i <= m; i++){
        now += add + tong[i];
        add += tag[i];
        ans = min(ans, now);
        //printf("i=%d tong=%d tag=%d now=%d\n", i, tong[i], tag[i], now);
    }
    cout<<ans<<endl;
    return 0;
}
