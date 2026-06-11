#include <bits/stdc++.h>
using namespace std;
char s[100005];
char t[100005];
int sA[100005];
int tA[100005];
int mem[3][3] = {
        {0, 2, 1},
        {1, 0, 2},
        {2, 1, 0}
};
int main(){
    scanf("%s",s+1);
    scanf("%s",t+1);
    int n = strlen(s+1);
    int m = strlen(t+1);
    for(int i = 1; i <= n; i++){
        sA[i] = sA[i-1] + (s[i] == 'A' ? 1 : 0);
    }
    for(int i = 1; i <= m; i++){
        tA[i] = tA[i-1] + (t[i] == 'A' ? 1 : 0);
    }
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int sa = sA[b] - sA[a-1];
        int sb = b-a+1 - sA[b] + sA[a-1];
        int ta = tA[d] - tA[c-1];
        int tb = d-c+1 - tA[d] + tA[c-1];
        sa %= 3;
        sb %= 3;
        ta %= 3;
        tb %= 3;
        if(mem[sa][sb] == mem[ta][tb]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}