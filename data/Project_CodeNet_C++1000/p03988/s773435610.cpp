#include <bits/stdc++.h>
using namespace std;

map<int,int> m;

int main(){
int n;
scanf("%d",&n);
int mn = 1000000005;
int mx = -1;
for (int x = 0; x<n; x++){
    int a;
    scanf("%d",&a);
    mn = min(mn,a);
    mx = max(mx,a);
    m[a]++;
}
if (mx%2==0){
    if (m[mn]!=1){
        printf("Impossible");
        return 0;
    }
}
else{
    if (m[mn]!=2){
        printf("Impossible");
        return 0;
    }
}
if (m[mx]<2){
    printf("Impossible");
    return 0;
}
if (mn!=(mx+1)/2){
    printf("Impossible");
    return 0;
}
for(int x = mn+1; x<=mx; x++){
    if (m[x]<2){
        printf("Impossible");
        return 0;
    }
}
printf("Possible");
}
