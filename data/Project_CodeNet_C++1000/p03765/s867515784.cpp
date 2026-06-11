#include <bits/stdc++.h>
using namespace std;
char s[100005], t[100005];
int sum1[2][100005], sum2[2][100005];
int main(){
    scanf("%s%s", s+1, t+1);
    int n = strlen(s+1), m = strlen(t+1);
    for(int i=1;i<=n;i++){
        sum1[s[i]-'A'][i]++;
        sum1[0][i] += sum1[0][i-1];
        sum1[1][i] += sum1[1][i-1];
    }
    for(int i=1;i<=m;i++){
        sum2[t[i]-'A'][i]++;
        sum2[0][i] += sum2[0][i-1];
        sum2[1][i] += sum2[1][i-1];
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int B1 = (sum1[0][b] - sum1[0][a-1])*2 + (sum1[1][b] - sum1[1][a-1]);
        int B2 = (sum2[0][d] - sum2[0][c-1])*2 + (sum2[1][d] - sum2[1][c-1]);
        if(B1%3 == B2%3) printf("YES\n");
        else printf("NO\n");
    }
}