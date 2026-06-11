#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define F first
#define S second
ll w,h,ans,k;
P o[200005];
int main(void){
    scanf("%lld%lld",&w,&h);
    for(int i=0;i<w;i++){
        scanf("%lld",&o[i].F);
        o[i].S=1;
    }
    for(int i=0;i<h;i++)scanf("%lld",&o[i+w].F);
    k=h+w;
    sort(o,o+k);
    h++;
    w++;
    for(int i=0;i<k;i++){
        if(o[i].S){
            ans+=o[i].F*h;
            w--;
        }else{
            ans+=o[i].F*w;
            h--;
        }
    }
    printf("%lld\n",ans);
}
