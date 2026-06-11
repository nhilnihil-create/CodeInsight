#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x;
  cin>>N>>x;
  if(x==1 || x==2*N-1){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  vector<int>n;
  for(int i=1;i<=2*N-1;i++){
    n.push_back(i);
  }
  int k=0;
  for(int i=1;i<=N-2;i++){
    if(n.at(k) != x-1 && n.at(k) != x && n.at(k) != x+1){
      cout<<n.at(k)<<endl;
      k++;
    }
    else{
      i--;
      k++;
    }
  }
  cout<<x-1<<endl;
  cout<<x<<endl;
  cout<<x+1<<endl;
  for(int i=1;i<=N-2;i++){
    if(n.at(k) != x-1 && n.at(k) != x && n.at(k) != x+1){
      cout<<n.at(k)<<endl;
      k++;
    }
    else{
      i--;
      k++;
    }
  }
  return 0;
}
