#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
void f(int p){
    int dx=0,dy=a[p]-p;
    for(int i = p+1;i<=n&&a[i]==p;++i){
        ++dx;
    }
    if((dx&1)||(dy&1))puts("First");
    else puts("Second");
}
int main()
{
    cin>>n;
    for(int i = 1;i <= n;++i)scanf("%d",&a[i]);
    if(n==1){
        if(a[1]&1)puts("Second");
        else puts("First");
        return 0;
    }
    sort(a+1,a+1+n,greater<int>());
    int p = 1;
    for(int i = 1;i <= n;++i){
        if(a[i+1]<i+1){
            p=i;
            break;
        }
    }
    f(p);
    return 0;
}
