#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  map<int,int> kaz;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    kaz[x]++;
  }
  int sum=0;
  for(auto & x:kaz){
    if(x.second%2==1) sum++;
  }
  cout<<sum<<endl;
}