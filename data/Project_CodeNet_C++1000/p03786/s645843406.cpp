#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
  }
  sort(p.begin(),p.end());
  vector<int64_t> WA(N);
  WA.at(0)=p.at(0);
  for(int i=1;i<N;i++){
    WA.at(i)=p.at(i)+WA.at(i-1);
  }
  int A=1;
  for(int i=N-2;i>=0;i--){
    if(WA.at(i)*2>=p.at(i+1)){
      A++;
    }
    else{
      break;
    }
  }
  cout<<A<<endl;
  
}