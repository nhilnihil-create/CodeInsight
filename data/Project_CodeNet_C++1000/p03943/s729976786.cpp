#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (a+b==c){
        printf("Yes\n");
    }
    else if (a+c==b){
        printf("Yes\n");
    }
    else if (b+c==a){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}