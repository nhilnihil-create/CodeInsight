#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,n,counter=0;
  cin>>N;
  vector<int>vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  for(int i=0;i<N;i++){
    if(i==0){
      if(vec.at(i)==2)
        break;
      n=vec.at(i);
      counter++;
    }
    else if(i<N-1){
      if(vec.at(n-1)==2){
        break;
      }
      else{
        n=vec.at(n-1);
        counter++;
      }
    }
    else if(i==N-1)
      counter = -2;
  }
  cout<<counter+1<<endl;
}