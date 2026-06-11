#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    scanf("%d%d",&n,&t);
    int a[n];
    int m;
    int maxdif = 0;
    int c1 = 0;
    int ans = 0;
    scanf("%d",&a[0]);
    m = a[0];
    for (int i = 1; i < n; i++) {
        scanf("%d",&a[i]);
        int dif = a[i]-m;
        if (dif > maxdif){
            maxdif = dif;
            c1 = 0;
        }
        if (dif == maxdif) c1++;
        m = min(m,a[i]);
    }
    printf("%d",c1);

}
