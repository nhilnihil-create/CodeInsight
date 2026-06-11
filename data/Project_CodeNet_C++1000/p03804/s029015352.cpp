#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int n,m;
char array1[55][55],array2[55][55];
bool solve(int i,int j){
    for(int k=0;k<m;++k){
        for(int l=0;l<m;++l){
            if(i+k<n&&j+l<n){
                if(array1[i+k][j+l]!=array2[k][l]){
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
int i,j,flag=0;
scanf("%d %d",&n,&m);
for(i=0;i<n;++i){
    for(j=0;j<n;++j){
        scanf(" %c",&array1[i][j]);
    }
}
for(i=0;i<m;++i){
    for(j=0;j<m;++j){
        scanf(" %c",&array2[i][j]);
    }
}
for(i=0;i<n;++i){
    for(j=0;j<n;++j){
       if(solve(i,j)){
         flag=1;
         break;
       }
    }
}
(flag)?printf("Yes"):printf("No");



    return 0;
}
