#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    ll x=1,i,lb,rb,mid;
    char tp[10];
    for(i=1;i<=13;i++,x*=10){
        printf("? %lld\n",x);fflush(stdout);
        scanf("%s",tp);
        if(tp[0]=='N') break;
    }
    if(i>13){
        for(i=1,x=10;i<=13;i++,x*=10){
            printf("? %lld\n",x-1);fflush(stdout);
            scanf("%s",tp);
            if(tp[0]=='Y') break;
        }
        printf("! %lld\n",x/10);fflush(stdout);
        return 0;
    }
    lb=x-1;rb=x*10;
    while(rb-lb>1){
        mid=lb+rb>>1;
        printf("? %lld\n",mid);fflush(stdout);
        scanf("%s",tp);
        if(tp[0]=='N') lb=mid;
        else rb=mid;
    }
    
    printf("! %lld\n",rb/10);fflush(stdout);
    return 0;
}
