#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int p[200005];
int b[200005];
int col[200005];
queue<int> q;
bool check(int X){
    memset(col,-1,sizeof(col));
    for (int i = 0; i < 2*n-1; i++){
        p[i] = a[i]>=X?1:0;
        //printf("%d ",p[i]);
    }
    //printf("IN\n");
    int ct = 1;
    int last = 0;
    for (int i = 1; i < 2*n-1; i++){
        if ((p[i] != p[i-1])){
            if (ct >= 2 || last == 0){
                col[last] = p[last];
                q.push(last);
                last = i-1;
                col[last] = p[last];
                q.push(last);
            }
            ct = 1;
            last = i;
        }
        else ct++;
    }
    col[last] = p[last];
    q.push(last);
    last = 2*n-2;
    col[last] = p[last];
    q.push(last);
    while (q.size()){
        int u = q.front(); q.pop();
        //printf("at %d\n",u);
        if (u >= 1 && col[u-1] == -1){
            col[u-1] = col[u];
            q.push(u-1);
        }
        if (u+1 < 2*n-1 && col[u+1] == -1){
            col[u+1] = col[u];
            q.push(u+1);
        }
    }
    /*for (int i = 0; i < 2*n-1; i++){
        printf("%d ",col[i]);
    }
    printf("OUT\n");*/
    return col[n-1];
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < 2*n-1; i++){
        scanf("%d",&a[i]);
    }
    int lo = 1, hi = 2*n-1;
    while (lo < hi){
        int X = (lo+hi+1)/2;
        if (check(X)) lo = X;
        else hi = X-1;
    }
    printf("%d ",lo);


}
