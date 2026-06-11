#include <bits/stdc++.h> 
using namespace std;
int n,a[400010],l,r,mid,ans;
bool S(int x){return !(x<=mid);}
bool check(){
    for(int i=1;i<=n-1;i++){
        if(S(a[n+i-1])==S(a[n+i]))	return S(a[n+i]);
        if(S(a[n-i+1])==S(a[n-i]))	return S(a[n-i+1]);
    }
    return S(a[1]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)	scanf("%d",&a[i]);
    l=1;r=2*n-1;
    while(l<=r){
        mid=(l+r)/2;
        if(!check())	r=mid-1,ans=mid;
		else			l=mid+1;
    }
    printf("%d\n",ans);
}