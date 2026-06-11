#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  vector<int> count(N,0);
  for(int i=0;i<N;i++){
    if(a.at(i)%2==0){
      count.at(i)=1;
    }
    if(a.at(i)%4==0){
      count.at(i)=2;
    }
  }
  int zero=0,one=0,two=0;
  for(int i=0;i<N;i++){
    if(count.at(i)==0){
      zero++;
    }else if(count.at(i)==1){
      one++;
    }else{
      two++;
    }
  }
  if(zero>two+1){
    cout<<"No"<<endl;
  }else if(zero==two+1&&one>0){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}
