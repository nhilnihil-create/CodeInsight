#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ans, base[22];
char s[4];
int num;
bool query(LL x){
    printf("? %lld\n", x);
    fflush(stdout);
    scanf("%s", s + 1);
    return s[1] == 'Y';
}
int main(){
    base[0] = 1;
    for(int i = 1;i <= 9; i++){
        base[i] = base[i-1] * 10ll;
        if(!num && !query(base[i])){
            num = i;
        }
    }
    if(!num){
        LL now = 9;
        for(int i = 0;i <= 9; i++){
            if(query(now)){
                printf("! %lld\n", base[i]);
                fflush(stdout);
                return 0;
            }
            now = now * 10ll;
        }
    }
    for(int i = num;i > 1; i--){
        int l = 0, r = 9, now = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(query(ans / base[i-1] + mid)){
                now = max(now, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans += 1LL * now * base[i-1];
    }
    for(int i = num == 1;i <= 9; i++){
        if(query((ans + i) * 10ll)){
            printf("! %lld\n", ans + i);
            fflush(stdout);
            break;
        }
    }
    return 0;
}
