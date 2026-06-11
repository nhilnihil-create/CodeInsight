#include<bits/stdc++.h>
int n,ans,a[233333];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    std::sort(a,a+n);
    for(int i=0;i<n;i++)ans+=(a[i]==a[i-1]);
    printf("%d\n",n-ans-(ans%2));
}