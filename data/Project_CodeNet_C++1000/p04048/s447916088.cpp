#include <bits/stdc++.h>
using namespace std;

long long n;
long long d;

int main(){
scanf("%lld%lld",&n,&d);
long long ans = 0;
ans += n;
long long width = d;
long long dist = n-d;
while (dist%width!=0){
    ans += 2LL * width * (dist/width);
    long long t = dist%width;
    dist = width;
    width = t;
}
ans += 2LL*width * (dist/width-1);
ans += width;
printf("%lld",ans);
}
