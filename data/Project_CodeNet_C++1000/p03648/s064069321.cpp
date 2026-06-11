#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    lli K;
    scanf("%lld",&K);

    printf("50\n");
    
    lli ad=K/50,rem=K%50;
    for(int i=0;i<rem;i++) {
        printf("%lld ",49 + ad + 50 - rem + 1);
    }
    for(int i=rem;i<50;i++) {
        printf("%lld ",49 + ad - rem);
    }
    
    return 0;
}
