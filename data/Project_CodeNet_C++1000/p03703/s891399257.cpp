#include<cstdio>
#include<algorithm>
long long sum[200005];
long long value[200005];
long long map[200005];
int bit[200005];

int getId(long long u,int n){
    int L = 1, R = n;
    int res = -1;
    while(L<=R){
        int M = (L+R)/2;
        if(map[M]<=u){
            res = M;
            L = M+1;
        }
        else R = M-1;
    }
    return res;
}

int preWork(int n){
    int size = 0;
    for(int i = 0; i <= n; i++) map[++size] = value[i];
    std::sort(map+1,map+1+size);
    int p = 1, nSize = 0;
    while(p<=size){
        int np = p;
        while(np+1<=size && map[np+1]==map[p]) np++;
        map[++nSize] = map[p];
        p = np+1;
    }
    for(int i = 0; i <= n; i++) value[i] = getId(value[i],nSize);
    return nSize;
}

void change(int p,int v,int n){
    while(p<=n){
        bit[p] += v;
        p += p&-p;
    }
}

int ask(int p){
    int res = 0;
    while(p!=0){
        res += bit[p];
        p -= p&-p;
    }
    return res;
}

int getSegSum(int l,int r){
    if(l>r) return 0;
    else return ask(r)-ask(l-1);
}

int main(){
    int n; long long k;
    scanf("%d%lld",&n,&k);
    sum[0] = value[0] = 0;
    for(int i = 1; i <= n; i++){
        long long u;
        scanf("%lld",&u);
        sum[i] = sum[i-1]+u;
        value[i] = sum[i]-k*(long long)i;
    }
    int size = preWork(n);
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        change(value[i],1,size);
        ans += (long long)getSegSum(value[i-1],size);
    }
    printf("%lld\n",ans);
    return 0;
}
