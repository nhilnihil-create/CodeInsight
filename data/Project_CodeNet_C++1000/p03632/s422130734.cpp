#include <bits/stdc++.h>
using namespace std;



int main(){
  

  vector<int> Alice(101);
  int A,B;
  cin>>A>>B;
  for(int i=A;i<=B;i++){
    Alice.at(i)=1;
  }
  vector<int> Bob(101);
  int C,D;
  cin>>C>>D;
  for(int i=C;i<=D;i++){
    Bob.at(i)=1;
  }
  
  int sum=0;
  for(int i=0;i<=100;i++){
    if(Alice.at(i)==1&&Bob.at(i)==1) sum+=1;
  }
  
  cout<<max(sum-1,0)<<endl;
}
