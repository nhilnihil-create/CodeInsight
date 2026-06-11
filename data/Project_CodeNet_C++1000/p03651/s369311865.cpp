        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 510000;
const int MOD =  1000000007;


     signed main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(k>a[n-1]){
      cout<<"IMPOSSIBLE"<<endl;
      return 0;
    }
    for(int i=1;i<n;i++){
      while(a[i-1]!=0){
        a[i]%=a[i-1];
        swap(a[i],a[i-1]);
      }
    }
    if(k%a[n-1]){
      cout<<"IMPOSSIBLE"<<endl;
    }else cout<<"POSSIBLE"<<endl;
                  
}


        
