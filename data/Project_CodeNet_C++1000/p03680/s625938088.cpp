#include <bits/stdc++.h>

using namespace std;
 
int main() {
  int n;
  cin >> n;
  int a=0;
  int sum=0;
  
  vector<int> vct(n);
  
  for(int i=0;i<n;i++){
    cin >>vct.at(i);
  }
  
  for(int i=0;i<n;i++){
    sum++;

    if(vct.at(a)==2){
      cout << sum<<endl;
      return 0;}
       a=vct.at(a)-1;
  }
  cout<<-1<<endl;


  }