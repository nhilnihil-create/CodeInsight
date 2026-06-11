#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long drops = 0;
    scanf("%lld", &n);
    long long onemove = n;
    onemove *= n + 1;
    onemove /= 2;
    long long tal = 0;
    long long val[n];
    for(long long i = 0; i < n; i++){
        scanf("%lld", &val[i]);
        tal += val[i];
    }
    if(tal % onemove != 0){
        printf("NO");
        return 0;
    }
    long long mves = tal / onemove;
    for(long long i = 0; i < n-1; i++){
        long long diff = val[i] - val[i+1];
        diff += mves;
        if(diff % n != 0 || diff < 0){
            printf("NO");
            return 0;
        }
        //printf("%lld\n", diff);
        drops += diff / n;
    }
    long long diff = val[n-1] - val[0];
    diff += mves;
    drops += diff / n;
    //printf("%lld %lld\n", mves, drops);
    if(diff % n != 0 || drops > mves || (mves-drops) % n != 0){
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}
