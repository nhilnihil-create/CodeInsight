#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  vector<int> vec(100002);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    vec.at(a+1)++;
  }
  int kaz=0;
  for(int i=1;i<=100000;i++){
    int tmp;
    tmp+=vec.at(i-1)+vec.at(i)+vec.at(i+1);
    kaz=max(kaz,tmp);
  }
  cout<<kaz<<endl;
    
  
}