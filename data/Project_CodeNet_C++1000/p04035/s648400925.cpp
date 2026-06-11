#include <bits/stdc++.h>
using namespace std;

int len[100005];
int n,l;

int main(){
scanf("%d%d",&n,&l);
for (int x = 0; x<n; x++){
    scanf("%d",&len[x]);
}
int maxf = -1;
int indf = -1;
for (int x = 1; x<n; x++){
    if (len[x]+len[x-1]>maxf){
        maxf = len[x]+len[x-1];
        indf = x;
    }
}
if (maxf<l){
    printf("Impossible");
    return 0;
}
printf("Possible\n");
for (int x = 1; x<indf; x++){
    printf("%d\n",x);
}
for (int x = n-1; x>=indf; x--){
    printf("%d\n",x);
}
}
