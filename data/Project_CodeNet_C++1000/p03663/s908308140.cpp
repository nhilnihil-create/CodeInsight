#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll k=1,a=10,ans=1;
bool que(ll x){
    printf("? %lld\n",x);
    fflush(stdout);
    char c;
    scanf(" %c",&c);
    return c=='Y';
}
int main(void){
    while(a<=100000000000&&que(a)){
        k++;
        a*=10;
    }
    if(k>10){
        a=2;
        while(!que(a)){
            a*=10;
        }
        printf("! %lld\n",a/2);
        return 0;
    }
    ll l=0,r=10;
    while(r-l>1){
        ll m=(l+r)/2;
        if(que(m*a))r=m;
        else l=m;
    }
    ans=l;
    for(int i=1;i<k;i++){
        l=-1;
        r=10;
        while(r-l>1){
            ll m=(l+r)/2;
            if(que((ans*10+m)*a))r=m;
            else l=m;
        }
        ans=ans*10+l;
        a/=10;
    }
    printf("! %lld\n",ans+1);
}
