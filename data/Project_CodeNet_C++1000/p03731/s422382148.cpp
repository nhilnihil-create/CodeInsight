#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin>>N>>T;
  int time=0;
  vector<int> vec(N);
  cin>>vec.at(0);
  for(int i=1;i<N;i++){
    cin>>vec.at(i);
    if(vec.at(i)-vec.at(i-1)>T) time+=T;
    else time+=vec.at(i)-vec.at(i-1);
  }
  cout<<time+T<<endl;
}