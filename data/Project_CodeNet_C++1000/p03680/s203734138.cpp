#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  int button=1;
  int count=0;
  bool can=false;
  set<int> S;
  S.insert(1);
  while(true){
    button=A.at(button-1);
    count++;
    if(button==2){
      can=true;
      break;
    }
    else if(S.count(button)) break;
    else S.insert(button);
  }
  cout<<(can?count:-1)<<endl;
}