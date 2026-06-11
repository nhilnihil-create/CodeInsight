#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n,a,b,c,d;
int main(){
    while(scanf("%lld",&n)==1){
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    for(int i=0;i<=n-1;i++){
        if((b-a)>=(i*c-(n-i-1)*d)&&(b-a)<=(i*d-(n-i-1)*c)){
            printf("YES");
            return 0;
            }
        }
    }
    printf("NO");
    return 0;    
}