#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;
char s[maxn], t[maxn];
int q;
int preas[maxn], prebs[maxn];
int preat[maxn], prebt[maxn];

int main(){
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for(int i = 1;i <= n;i++){
        preas[i] = preas[i - 1] + (s[i] == 'A');
        prebs[i] = prebs[i - 1] + (s[i] == 'B');
    }
    for(int i = 1;i <= m;i++){
        preat[i] = preat[i - 1] + (t[i] == 'A');
        prebt[i] = prebt[i - 1] + (t[i] == 'B');
    }
    cin >> q;
    while(q--){
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        int cnt1 = preas[r1] - preas[l1 - 1];
        int cnt2 = prebs[r1] - prebs[l1 - 1];
        int cnt3 = preat[r2] - preat[l2 - 1];
        int cnt4 = prebt[r2] - prebt[l2 - 1];
        if(((cnt4 - cnt3) - (cnt2 - cnt1)) % 3 == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
