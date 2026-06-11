#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  long long n,m,r,ans=1e15,a,b,c;
  cin >> n >> m >> r;
  vector<long long> t(r);
  for(int i=0;i<r;i++){
    cin >> t[i];
    t[i]--;
  }
  sort(t.begin(), t.end());
  long long flo[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        flo[i][j]=0;
      }else{
        flo[i][j]=1e15;
      }
    }
  }
  for(int i=0;i<m;i++){
    cin >> a >> b >> c;
    a--; b--;
    flo[a][b]=c;
    flo[b][a]=c;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        flo[j][k] = min(flo[j][k], flo[j][i]+flo[i][k]);
      }
    }
  }
  do{
    long long sum=0;
    for(size_t i=1;i<t.size();i++){
      sum+=flo[t[i-1]][t[i]];
    }
    ans=min(ans, sum);
  }while(next_permutation(t.begin(), t.end()));
  cout << ans << endl;
  return 0;
}
