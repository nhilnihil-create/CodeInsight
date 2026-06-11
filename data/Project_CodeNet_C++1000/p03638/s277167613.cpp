#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1000000;
const int MOD = 1000000007;

signed main() {
 int h,w,n;
 cin>>h>>w>>n;
 int a[n],c[w];
 for(int i=0;i<n;i++)cin>>a[i];
 int k=0;
 for(int i=0;i<h;i++ ){
     if(i%2){
         for(int j=0;j<w;j++){
             if(a[k]==0)k++;
             c[j]=k+1;a[k]--;
         }
     }else{
          for(int j=w-1;j>=0;j--){
             if(a[k]==0)k++;
             c[j]=k+1;a[k]--;
         }
     }
     for(int j=0;j<w;j++)cout<<c[j]<<' ';
     cout<<endl;
 }

return 0;
}
