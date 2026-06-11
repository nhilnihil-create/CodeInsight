        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

 
     signed main(){
     int h,w,d;
     cin>>h>>w>>d;
     char ans[4];
     ans[0]='R';ans[1]='Y';ans[2]='G';ans[3]='B';
     for(int i=0;i<h;i++){for(int j=0;j<w;j++){
          cout<<ans[(MOD*d+i-j)/d%2*2+(MOD*d+i+j)/d%2];
     }
     cout<<endl;
     }
     

   

      }

        