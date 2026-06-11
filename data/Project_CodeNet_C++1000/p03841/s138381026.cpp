#include <bits/stdc++.h>
 
using namespace std;
#define int long long

const int MAX = 1000000007;
 
 


 
signed main(){
    int n,x0,y;
    cin>> n;
    pair<int,int> x[n];
    int ans[n*n]={};
    for(int i=1;i<=n;i++){
        cin>>x0;
        ans[x0-1]=i;
        x[i-1]=make_pair(x0-1,i);
    }
    sort(x,x+n);
    int t=0;
    for(int i=0;i<n;i++){
        y=x[i].second-1;
      // cerr<<y;
        while(y!=0&&t<x[i].first){
            if(ans[t]==0){
                 ans[t]=x[i].second;
                 y--;
              //   cerr<<t<<' '<<ans[t]<<endl;
            }
           
            t++;
         
        }
        if(y!=0){
            cout<<"No";
            return 0;
        }

    }
    t=n*n-1;
    for(int i=n-1;i>=0;i--){
        y=n-x[i].second;
       
        while(y!=0&&t>x[i].first){
            if(ans[t]==0){
                 ans[t]=x[i].second;
                 y--;
                 //cerr<<t<<' '<<ans[t]<<endl;
            }
           
            t--;
         
        }
        if(y!=0){
            cout<<"No";
            return 0;
        }

    }
    cout<<"Yes"<<endl;
    for(int i=0;i<n*n;i++)cout<<ans[i]<<' ';

   
    
    return 0;
}