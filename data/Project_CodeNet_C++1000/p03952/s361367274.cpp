        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  998244353;

     signed main(){
      
      int n,x;
      cin>>n>>x;
      if(x==1||x==2*n-1){
           cout<<"No"<<endl;
           return 0;
      }
      cout<<"Yes"<<endl;
      int ans[2*n-1];
     for(int i=0;i<2*n-1;i++)ans[i]=1+(2*n-1+i+x-n)%(2*n-1);
     swap(ans[n],ans[n-2]);
     for(int i=0;i<2*n-1;i++)cout<<ans[i]<<endl;





      }

        
