#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (a==b && b!=c){
        printf("2\n");
    }
    else if (a==c && b!=c){
        printf("2\n");
    }
    else if (b==c && a!=b){
        printf("2\n");
    }
    else if (a==b && b==c){
        printf("1\n");
    }
    else{
        printf("3\n");
    }
}