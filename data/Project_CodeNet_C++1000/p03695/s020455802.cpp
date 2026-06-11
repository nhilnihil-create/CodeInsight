#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int m,oth=0;
  vector<int>iro(8,0);
  for(int i=0;i<n;i++){
    cin >> m;
    if(m<3200){
      iro.at(m/400)++;
    }else{
      oth++;
    }
  }
  int ans=0;
  for(int i=0;i<8;i++){
    if(iro.at(i)>0)
      ans++;
  }
  cout << max(ans,1) << " " << ans+oth << endl;
  return 0;
}