#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int n,a[110000];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    a[0]=a[1];
    for (int i=0;i<=n;i++)
        if (a[i+1]<=i){
            int j=i+1;
            while (j<=n&&a[j]==i) j++;
            if ((j-i+1)&1||(a[i]-i)&1) puts("First");
            else puts("Second");
            break;
        } 
    return 0;
}
//atcoder 1999