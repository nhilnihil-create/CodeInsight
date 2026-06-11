        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  1000000007;

     signed main(){
         int n;
         cin>>n;
         int x[n];
         for(int i=0;i<n;i++)cin>>x[i];
         int r[20][n];
         int l;cin>>l;
         int m=0;
         for(int i=0;i<n;i++){
              while(m<n&&x[m]-x[i]<=l)m++;
              r[0][i]=m-1;
         }
         for(int i=1;i<20;i++)for(int j=0;j<n;j++)r[i][j]=r[i-1][r[i-1][j]];
         int q,a,b,ans;cin>>q;
          for(int i=0;i<q;i++){
               cin>>a>>b;a--;b--;
               if(a>b)swap(a,b);
               ans=0;
               while(true){
                    int j=0;
                    while(b>r[j][a])j++;
                    if(j==0){
                         ans+=(1<<j);
                         break;
                    }
                    ans+=(1<<(j-1));
                    a=r[j-1][a];
               }
               cout<<ans<<endl;
          }

      }

        
