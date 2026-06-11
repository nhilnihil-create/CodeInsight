#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,m,i,j;
char array1[100][100];
scanf("%d %d",&n,&m);
for(i=0;i<n;++i){
    for(j=0;j<m;++j){
        scanf(" %c",&array1[i][j]);
    }
}
for(i=0;i<m+2;++i){
    printf("#");
}
printf("\n");
for(i=0;i<n;++i){
    printf("#");
    for(j=0;j<m;++j){
        printf("%c",array1[i][j]);
    }
    printf("#\n");
}
for(i=0;i<m+2;++i){
    printf("#");
}

    return 0;
}
