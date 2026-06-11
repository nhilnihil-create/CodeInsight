#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
    int N,A,B;
    scanf("%d%d%d",&N,&A,&B);
    if(B<A)
        printf("0\n");
    else if(B==A){
        printf("1\n");
    }
    else{
        if(N==1)
            printf("0\n");
        else{
            printf("%lld\n",(long long)(N-2)*(B-A)+1);
        }
    }
    return 0;
}
