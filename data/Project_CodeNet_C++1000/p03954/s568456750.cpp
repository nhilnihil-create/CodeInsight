#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
map<int,int>ma;
int n,l,r,a[N],b[N],c[N];
bool check(int x){
    int l=0,r=0,tl=0,tr=0;
    for(register int i=1;i<=n;i++) b[i]=(a[i]>x);
    for(register int i=(n+1)>>1;i<=n;i++){
        if(b[i]==b[i+1]){
            tr=b[i];
            break;
        }
        ++r;
    }
    for(register int i=(n+1)>>1;i;i--){
        if(b[i]==b[i-1]){
            tl=b[i];
            break;
        }
        ++l;
    }
    if(l<r) tr=tl;
    if(min(l,r)>=(n+1)/2)    tr=b[(n+1)/2]^(((n+3)/2)%2);
    return tr;
}
int main(){
    scanf("%d",&n),n=n*2-1;
    for(register int i=1;i<=n;i++)
        scanf("%d",&a[i]),c[i]=a[i];
    sort(c+1,c+n+1),b[0]=b[n+1]=-1;
    for(register int i=1;i<=n;i++)   ma[c[i]]=i;
    for(register int i=1;i<=n;i++)   a[i]=ma[a[i]];
    register int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))  l=++mid;
        else    r=mid;
    }
    printf("%d\n",c[l]);
    return 0;
}