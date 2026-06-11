#include <bits/stdc++.h>
using namespace std;

int occ[100005];

int main(){
int m,n;
scanf("%d%d",&m,&n);
for (int x = 0; x<n; x++){
    int a,b;
    scanf("%d%d",&a,&b);
    occ[a]++;occ[b]++;
}
for (int x = 0; x<=n; x++){
    if (occ[x]&1){
        printf("NO");
        return 0;
    }
}
printf("YES");
}
