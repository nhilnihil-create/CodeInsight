
#include<cstdio>
#include<cstdlib>
#define LL long long
using namespace std;
int main() {
    LL x,y;
    scanf("%lld%lld",&x,&y);
    if(llabs(x-y)>=2)
        printf("Alice\n");
    else
        printf("Brown\n");
    return 0;
}
