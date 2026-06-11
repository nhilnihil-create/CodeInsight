#include <bits/stdc++.h>
 
using namespace std;
//#define int long long


 const int MAX = 1001;
const int MOD = 1000000007;



signed main(){
    int n,m;
    cin>>n>>m;
    int l[n],r[n],t,ok,ng,mid;
    int ans[m+1]={},ans2[m+1]={};
      for(int i=0;i<n;i++)cin>>l[i]>>r[i];
    for(int i=0;i<n;i++){
       // cin>>l>>r;
       ng=sqrt(r[i]);
        for(int j=1;j<=ng;j++){
             if(r[i]%j<=r[i]-l[i]){
                ans[j]++;
                 ok=r[i]/j;
                 //ng=r/(j+1);
                 if(ok>ng){
                 ans2[ok]--;
                 ans2[max(r[i]/(j+1),max((l[i]-1)/j,ng))]++;
             //   cerr<<l/j<<endl;
                //cerr<<ng<<endl;
                 }
            }
           
           
        }
    }
    t=0;
    for(int i=1;i<=m;i++){
        t+=ans2[i-1];
      //  cerr<<ans[i]<<' '<<t<<endl;
        cout<<ans[i]+t<<endl;

    }

    

   return 0;
}