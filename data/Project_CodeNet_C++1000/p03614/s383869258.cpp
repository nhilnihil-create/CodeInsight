#include <bits/stdc++.h>
using namespace std;

int n,arr[100001];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);

    int ans=0;
    for(int i=1,j;i<=n;i=j) {
        if(arr[i]!=i) {
            j=i+1;
            continue;
        }
        for(j=i;j<=n && arr[j]==j;j++);
        ans += (j-i+1)/2;
    }
    printf("%d\n",ans);
    return 0;
}
