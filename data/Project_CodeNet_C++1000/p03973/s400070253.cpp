#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int n;
ll p=1,s;
int main(void){
    scanf("%d%lld",&n,&s);
    s--;
    for(int i=0;i<n-1;i++){
        ll a;
        scanf("%lld",&a);
        if(a==p+1)p=a;
        else s+=(a-1)/(p+1);
    }
    printf("%lld\n",s);
}
