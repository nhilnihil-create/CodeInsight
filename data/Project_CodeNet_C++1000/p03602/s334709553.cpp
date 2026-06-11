#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n));
  LL total=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin >> a[i][j];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      total+=a[i][j];
    }
  }
  vector<vector<bool>> ok(n,vector<bool>(n,true));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=j+1;k<n;k++){
        if(a[j][k]>a[j][i]+a[i][k]){
          cout << -1 << endl;
          return 0;
        }else if(ok[j][k]&&i!=j&&i!=k&&a[j][k]==a[j][i]+a[i][k]){
          total-=a[j][k];
          ok[j][k]=false;
        }
      }
    }
  }
  cout << total << endl;
  return 0;
}
