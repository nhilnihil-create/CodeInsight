#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005];
inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    int dis1=0,dis2=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++){
        if(a[i+1]<i+1){
            dis1=a[i]-i;
            for (int j=i+1;j<=n;j++){
                if(a[j]==i){
                    dis2++;
                }else{
                    break;
                }
            }
            break;
        }
    }
    dis1&=1,dis2&=1;
    printf("%s\n",!(dis1+dis2)?"Second":"First");
    return 0;
}