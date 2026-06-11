#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> count(N,0);
  int max=0,break_num;
  
  for(int i=0;i<N;i++){
    int a=i+1;
    
    while(a%2==0){
      a/=2;
      count.at(i)++;
    }
    
    if(count.at(i)>=max){
      max=count.at(i);
      break_num=i+1;
    }
    
  }
  cout << break_num << endl;
}