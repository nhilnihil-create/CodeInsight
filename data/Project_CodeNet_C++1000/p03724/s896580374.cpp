#include <bits/stdc++.h>
using namespace std;
int ct[100005];
int main(){
 	int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ct[x]++; ct[y]++;
    }
    for (int i = 1; i <= n; i++){
        if (ct[i] & 1){
            printf("NO");
            return 0;
        }
    }
    printf("YES");


}
