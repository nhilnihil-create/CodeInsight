#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    long long ans = 1, m = 1e9 + 7;

    for(long long i=0; i<n; i++){
        ans *= i + 1;
        ans %= m;
    }
    
    printf("%lld\n", ans);

    return 0;
}