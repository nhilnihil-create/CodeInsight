#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N];
int n,A,B,C;
bool check(ll);
int main(){
    scanf("%d%d%d",&n,&A,&B);
    C=A-B;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    ll l=0,r=2e9,mid;
    while(l<r){
        mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l;
}
bool check(ll x){
    ll cnt=0,sum=x*B;
    for(int i=1;i<=n;i++)if(a[i]>sum){
        cnt+=(a[i]-sum+C-1)/C;
    }
    return cnt<=x;
}
