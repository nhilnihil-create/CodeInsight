#include <bits/stdc++.h>

using namespace std;

int main(){

  long long int n, m;
  cin>>n>>m;

  long long int a[n][2], c[m][2];

  for(int i=0; i<n; i++) cin>>a[i][0]>>a[i][1];
  for(int j=0; j<m; j++) cin>>c[j][0]>>c[j][1];
  
  int ans=0;
  for(int i=0; i<n; i++){
    long long int min_dist=10000000000000000; 
    for(int j=0; j<m; j++){
      long long int sTc=abs(a[i][0]-c[j][0])+abs(a[i][1]-c[j][1]);
      if(min_dist>sTc){
        ans=j+1;
      }
      min_dist=min(min_dist, sTc);
      
    }
    cout<<ans<<endl;
  }


}
