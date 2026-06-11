#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int n, a[N], ma; 
int main(){
    cin>>n;
    for(int i = 1;i <= n; i++){
        scanf("%d", &a[i]);
        ma = max(ma, a[i]);
    }
    int dl = 0;
    for(int i = 1;i <= n; i++){
        if(ma - a[i] > 1){
            puts("No");
            return 0;
        }
        else if(ma - a[i])dl++;
    }
    if(dl == 0){
        if(ma == n - 1 || ma * 2 <= n)puts("Yes");
        else puts("No");
    }
    else{
        if(n - dl < 2 * (ma - dl) || ma <= dl) puts("No");
        else puts("Yes");
    }
    return 0;
}
