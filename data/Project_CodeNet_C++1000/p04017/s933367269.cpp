#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    int p[n][18]; memset(p,-1,sizeof(p));
    int l;
    scanf("%d",&l);
    int cur = 0;
    for (int i = 0; i < n; i++){
        while (cur < n && a[cur] - a[i] <= l) cur++;
        cur--;
        p[i][0] = cur;
        //printf("%d %d\n",i,cur);
    }
    for (int i = n-1; i >= 0; i--){
        for (int j = 1; j < 18; j++){
            if (p[i][j-1] == -1) break;
            p[i][j] = p[p[i][j-1]][j-1];
            //printf("%d %d %d\n",i,j,p[i][j]);
        }
    }
    int q;
    scanf("%d",&q);
    for (int i =0;  i < q; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        if (a > b) swap(a,b);
        int cur = a;
        int sum = 0;
        for (int k = 17; k >= 0; k--){
            if (p[cur][k] < b){
                cur = p[cur][k];
                sum += (1<<k);
            }
        }
        printf("%d\n",sum+1);
    }

}
