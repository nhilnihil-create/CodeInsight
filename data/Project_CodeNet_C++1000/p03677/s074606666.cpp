#include<cstdio>
#include<vector>
int a[100005];
int start[100005];
int solid[100005];
std::vector<int> end[100005];

int getCost(int l,int r,int m){
    if(r>=l) return r-l;
    else return r-l+m;
}

int min(int a,int b){ return a>b?b:a; }

long long calCost(int x,int n,int m){
    long long res = 0;
    for(int i = 1; i <= n-1; i++){
        long long add = min(getCost(a[i],a[i+1],m),1+getCost(x,a[i+1],m));
        res += add;
    }
    return res;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){ 
        scanf("%d",&a[i]);
        a[i]--;
    }
    //for(int i = 1; i <= n; i++) printf("%d ",a[i]);
    //printf("\n");
    int cnt = 0;
    for(int i = 1; i <= n-1; i++){
        int l = (a[i]+1)%m, r = a[i+1];
        solid[i] = getCost(a[i],a[i+1],m);
        start[l]++;
        end[r].push_back(i);
        if(l>r) cnt++;
    }
    long long ans = calCost(0,n,m);
    //printf("ans = %lld\n",ans);
    long long sum = ans;
    for(int i = 0; i < m-1/*?*/; i++){
        cnt = cnt+start[i]-(int)end[i].size();
        //printf("i = %d, cnt = %d\n",i,cnt);
        for(int u: end[i]){
            sum = sum-1ll+(long long)solid[u];
        }
        sum -= (long long)cnt;
        if(ans>sum) ans = sum;
    }
    printf("%lld\n",ans);
    return 0;
}
