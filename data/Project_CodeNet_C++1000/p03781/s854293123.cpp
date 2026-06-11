#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n,i,sum=0;
    while (scanf("%lld",&n)!=EOF){
    sum=0;
    for (i=1;sum<n;i++){
        sum+=i;
    }
        printf("%lld\n",i-1);
    }
    return 0;
}
