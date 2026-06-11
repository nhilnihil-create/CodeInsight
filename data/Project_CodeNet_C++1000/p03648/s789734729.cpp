#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long LL;

const int Maxn = 200000;

int main(){
    LL k, a[Maxn];
    while(~scanf("%lld", &k)){
        for(int i = 1; i <= 50; i++) a[i] = k/50LL + i - 1;
        k %= 50;
        for(int i = 1; i*1LL <= k; i++){
            for(int j = 1; j <= 50; j++) a[j]--;
            a[i] += 51;
        }
        printf("50\n");
        for(int i = 1; i < 50; i++) printf("%lld ", a[i]);
        printf("%lld\n", a[50]);
    }
    return 0;
}