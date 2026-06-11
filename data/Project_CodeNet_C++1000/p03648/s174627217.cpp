#include <iostream>
#include<iomanip>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

const int NN=5e6+10;

long long n;
long long a[100][100];


int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=50;i++){
        a[i][1]=50;
    }
    for(int i=1;i<=50;i++){
        for(int j=2;j<=50;j++){
            if(j>i){
                a[i][j]=a[i][i]-2;
            }
            else{
                a[i][j]=a[i][j-1]-1;
            }
        }
    }
    /*
    for(int i=1;i<=50;i++){
        for(int j=1;j<=50;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    printf("50\n");
    long long ans=n/50;
    if(n==50) {
        ans=0;
    }
    else if(n%50==0&&n>50){
        ans=ans-1;
    }
    int ans2=n%50;
    if(ans2==0) ans2=50;
    if(n==0) ans2=0;
    printf("%lld",a[ans2][1]+ans);
    for(int i=2;i<=50;i++){
        printf(" %lld",a[ans2][i]+ans);
    }
    printf("\n");
    return 0;
}