#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  
  vector<int> gone(N,0);
  gone.at(1)=2;
  bool check=true;
  int i=0;
  int ans=0;
  while(check){
    if(gone.at(i)==0){
      gone.at(i)=1;
      i=a.at(i)-1;
      ans++;
    }
    else if(gone.at(i)==2)
      break;
    else
      check=false;
  }
  if(check)
    cout<<ans<<endl;
  else
    cout<<"-1"<<endl;
}
