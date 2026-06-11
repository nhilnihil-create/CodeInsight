        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

     signed main(){
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    if(h%a==0&&w%b==0){
         cout<<"No"<<endl;
         return 0;
    }
    cout<<"Yes"<<endl;
    int ans[h+1][w+1];
    for(int i=0;i<h+1;i++)for(int j=0;j<w+1;j++){
         if(i>=a&&j>=b)ans[i][j]=ans[i][j-b]+ans[i-a][j]-ans[i-a][j-b]-1;
         else ans[i][j]=0;
    }
    int p=ans[h][w]-1;
    if(w%b)for(int j=w;j>=0;j-=b)ans[h][j]-=p;
    else for(int i=h;i>=0;i-=a)ans[i][w]-=p;
    for(int i=1;i<=h;i++){
         for(int j=1;j<=w;j++){
               
                    cout<<ans[i][j]+ans[i-1][j-1]-ans[i][j-1]-ans[i-1][j]<<' ';
              
         }
          cout<<endl;
    }
   
    




    }





      

        
