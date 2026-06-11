#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  std::vector<int> p(N);
  for(int i=0;i<N;i++)cin>>p[i];
  int ans=0;
  for(int i=0;i<N;i++){
    if(p[i]==i+1){
      if(i<N-1){
        if(p[i+1]==i+2){
          ans++;
          i++;
        }
        else ans++;
      }
      else ans++;
    }
  }
  cout<<ans<<endl;
}
