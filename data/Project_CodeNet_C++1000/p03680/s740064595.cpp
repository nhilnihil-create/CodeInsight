#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  int a=1;
  for(int i=1;i<N;i++){
    a=vec.at(a-1);
    if(a==2){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}