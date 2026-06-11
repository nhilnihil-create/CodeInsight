#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define INF 1e+10
#define MAX_V 10
 
 
// <最短距離, 頂点の番号>
using P = pair<int, int>;

 
 
signed main(){
    int n;
    cin >> n;
    int a[n][n];
    int b[n][n];
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];

            b[i][j]=a[i][j];
        }
     
    }
   
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[i][j] > a[i][k]+a[j][k]){
                    t=1;
                    break;
                }
                if(i!=k&&j!=k&&a[i][j] == a[i][k]+a[j][k]){b[i][j]=0;b[j][i]=0;}
            }
        }
        
    }
  
      int ans=0;
    if(t==1){ans = -1;
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=b[i][j];
            }
        }
    }
   cout << ans;
     return 0;
    }
   


