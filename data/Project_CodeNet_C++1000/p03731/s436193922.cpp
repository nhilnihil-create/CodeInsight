#include <bits/stdc++.h>
using namespace std;





int main() {
  int64_t n,t;
  cin>>n>>t;
  
  vector<int64_t> data(n);
  
  for (int64_t i=0;i<n;i++){
    cin>>data.at(i);
  }
  

  int64_t answer=0;
  
  for (int64_t i=0;i<n-1;i++){
    answer+=min(data.at(i+1)-data.at(i),t);
  }
  
  answer+=t;
  
  cout<<answer<<endl;
  
  

    
    
    
    
}











