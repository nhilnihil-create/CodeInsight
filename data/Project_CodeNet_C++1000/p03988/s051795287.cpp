#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,maxn,minn=1e9,a[105];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    if(minn!=(maxn+1)/2){
        puts("Impossible");
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==minn){
            cnt++;
        }
    }
    if(cnt!=(maxn&1)+1){
        puts("Impossible");
        return 0;
    }
    for(int i=minn+1;i<=maxn;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                cnt++;
            }
        }
        if(cnt==0||cnt==1){
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    return 0;
}