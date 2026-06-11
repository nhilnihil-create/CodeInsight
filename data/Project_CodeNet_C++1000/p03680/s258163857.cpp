#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int p=1;
  int ans=0;
  vector<int> s(N);
  for(int i=0;i<N;i++){
    cin>>s.at(i);
  }
  while(true){
    if(s.at(p-1)==2){
      ans++;
      break;
    }
    p=s.at(p-1);
    ans++;
    if(ans>100000){
      cout<<-1<<endl;
      break;
    }
  }
  if(ans<=100000){
    cout<<ans<<endl;
  }
}
