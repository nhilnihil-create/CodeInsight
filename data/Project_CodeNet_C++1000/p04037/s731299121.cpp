
#include <bits/stdc++.h>
using namespace std;
 
int a[100005];
 
int main(){
    int n,i;cin>>n;
    for(i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(i=1;i<=n;++i){
        if(a[i+1]<i+1 && a[i]>=i){
            int j=0;
            while(a[j+i+1]==i) j++;
            if((a[i]-i)%2==0 && j%2==0) puts("Second");
            else puts("First");
        }
    }
}