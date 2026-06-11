        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;


     signed main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
int ans=0,ans2=0;
for(int i=0;i<n;i++)ans+=a[i];
for(int i=0;i<n;i++){
     if(a[i]==0){
          ans-=ans2%2;
          ans2=0;
     }
     ans2+=a[i]%2;
}
cout<<ans/2<<endl;


 }

 


 






    





      

        
