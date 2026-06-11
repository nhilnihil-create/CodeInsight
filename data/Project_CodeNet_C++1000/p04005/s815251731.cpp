#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    if(~A&1||~B&1||~C&1){puts("0");return 0;}
    cout<<min(min(1LL*A*B,1LL*B*C),1LL*A*C)<<endl;
}