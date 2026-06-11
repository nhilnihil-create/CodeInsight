        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 200004;
const int MOD =998244353
 ;
const int INV2 = (MOD+1)/2;
int k,x,y;


     signed main(){
          int n;
          cin>>n;
         int s[n];
         for(int i=0;i<n;i++)cin>>s[i];
         bool k[10001]={};
         k[0]=true;
         for(int i=0;i<n;i++){
              for(int j=10000;j>=s[i];j--){
                   k[j]|=k[j-s[i]];
              }
         }
         for(int i=10000;i>=0;i--)if(i%10&&k[i]){
              cout<<i<<endl;
              return 0;
         }
         cout<<0<<endl;
         return 0;

        





}


        
