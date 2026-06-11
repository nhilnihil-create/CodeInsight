#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int main(){
    ll a,b,x;
    while(~scanf("%lld%lld%lld",&a,&b,&x)){
        if(a){
            printf("%lld\n",b/x-(a-1)/x);
        }
        else{
            printf("%lld\n",b/x+1);
        }
    }
    return 0;
}
