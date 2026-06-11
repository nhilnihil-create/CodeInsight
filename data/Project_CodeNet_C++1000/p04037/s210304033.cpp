#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[100100];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(i+1>a[i+1]){
            int ans=0;
            for(int j=i+1;a[j]==i;j++)
                ans^=1;
            if(ans||((a[i]-i)&1))
                printf("First\n");
            else
                printf("Second\n");
            return 0;
        }
    }
    return 0;
}