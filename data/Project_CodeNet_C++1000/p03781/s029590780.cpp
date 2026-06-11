#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
int main(){
    scanf("%d",&x);
    int l=0,r=100000;
    int mid,ans;
    while(l<=r){
        mid=l+r>>1;
        if(1ll*mid*(mid+1)/2>=x)ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}