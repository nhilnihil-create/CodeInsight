#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    scanf("%i%i",&a,&b);
    if(a<=0 && b>=0) printf("Zero\n");
    else if((a>0 && b>0) || (a<0 && b<0 && (b-a)%2==1)) printf("Positive\n");
    else printf("Negative\n");
    return 0;
}