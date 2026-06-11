#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n,m;
  cin>>n>>m;
  
  vector<int>a(m);
  vector<int>b(m);
  for(int i=0;i<m;i++){
   cin>>a.at(i)>>b.at(i); 
  }
  
  vector<int>count(n);
  for(int i=0;i<m;i++){
    count.at(a.at(i)-1)++;
    count.at(b.at(i)-1)++;
  }
  
  for(int i=0;i<n;i++){
    cout<<count.at(i)<<endl; 
  }
  return 0;
}