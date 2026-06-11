#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
LL freq[100005];
int main()
{
LL i,n,sum=0,k;
scanf("%lld %lld",&n,&k);
while(n--){
    LL num,freqs;
    scanf("%lld %lld",&num,&freqs);
    freq[num]+=freqs;
}
for(i=1;i<=100005;++i){
    sum+=freq[i];
    if(sum>=k){
        printf("%lld",i);
        return 0;
    }
}



    return 0;
}
