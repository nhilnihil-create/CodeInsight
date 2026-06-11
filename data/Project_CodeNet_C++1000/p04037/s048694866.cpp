#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, greater<int>());
    for(int i = 1; i <= n; ++i){
        if(i + 1 > a[i + 1]){
            int p = 0;
            while(a[p + i + 1] == i) ++p;
            if(p & 1 || (a[i] - i) & 1) printf("First");
            else printf("Second");
            break;
        }
    }
}