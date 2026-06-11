#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100100];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i>=a[i+1]){
               for(int j=i+1;a[j]==i;j++) ans^=1;
               ans|=(a[i]-i)&1;
               if(ans)cout<<"First"<<endl;
               else cout<<"Second"<<endl;
               return 0;
           }    
    }    
}