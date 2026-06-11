#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,p=1,c=0;
  cin>>N;
  vector<int> s(N);
  
  for(int i;i<N;i++){
    cin>>s.at(i);
  }  
  
  while(true){
    p=s.at(p-1);
    c++;
    if(p==2)break;
    else if(c>N){
      c=-1;
      break;
    }
  }
  cout<<c<<endl;
}