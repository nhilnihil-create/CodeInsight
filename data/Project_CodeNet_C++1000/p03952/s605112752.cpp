#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
int a[N];
int main(){
    int n,x; scanf("%d%d",&n,&x);
    if(x==1||x==2*n-1) puts("No");
    else{
        puts("Yes");
        int p = n, v = x;
        for(int i=1;i<=2*n-1;i++){
            a[p] = v;
            p = p + 1, v = v + 1;
            if(p>2*n-1) p -= 2*n-1;
            if(v>2*n-1) v -= 2*n-1;
        }
        for(int i=1;i<=2*n-1;i++) printf("%d%c",a[i]," \n"[i==2*n-1]);
    }
}
