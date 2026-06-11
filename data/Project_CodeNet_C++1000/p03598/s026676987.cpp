        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX =2000007;
const int MOD = 1000000007;
//

     signed main(){
   int n,k;
   cin>>n>>k;
   int x,ans=0;
   for(int i=0;i<n;i++){
       cin>>x;
       ans+=min(x,k-x);
   }
   cout<<2*ans<<endl;

     }


 


 






    





      

        
