#include<cstdio>
int a[100005], b[100005];

int main(){
    //printf("%d\n",1<<30);
    int n,k;
    scanf("%d%d",&n,&k);
    //maxbit: 2^29 -> 1<<29
    for(int i = 1; i <= n; i++) scanf("%d%d",&a[i],&b[i]);
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        int left = a[i]&(~k);
        if(left==0) ans += (long long)b[i];
    }
    //first diff pos
    int allOne = (1<<30)-1;
    for(int i = 29; i >= 0; i--){
        if(((1<<i)&k)==0) continue;
        int upper = allOne^((1<<(i+1))-1);
        int bad = ~(k&upper);
        long long cur = 0;
        for(int j = 1; j <= n; j++){
            if(a[j]&(1<<i)) continue;
            int left = a[j]&upper;
            if((left&bad)==0) cur += (long long)b[j];
        }
        if(cur>ans) ans = cur;
    }
    printf("%lld\n",ans);
    return 0;
}
