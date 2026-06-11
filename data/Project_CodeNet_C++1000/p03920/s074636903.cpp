        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

     signed main(){
 int n;
 cin>>n;
 for(int i=1;;i++){
      if(i*(i+1)>=2*n){
           for(int j=1;j<=i;j++){
                if(j!=i*(i+1)/2 - n){
                     cout<<j<<endl;
                }
           }
           return 0;
      }
 }






    }





      

        
