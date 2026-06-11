#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    int sg=0;
    for(int i=1;i<=n;i++){
        if(a[i+1]<=i){
            int pos=i;
            while(a[pos+1]==i)pos++;
            if((a[i]-i+1)&(pos-i+1)&1)puts("Second");
            else puts("First");
            break;
        }
    }
    return 0;
}
