#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long n, a, i;
  cin>>n;
  deque<long long> data;
  for(i=0;i<n;i++){
    cin>>a;
    if((i+n%2)%2==1){
      data.push_front(a);
    }else{
      data.push_back(a);
    }
  }
  
  for(i=0;i<n;i++){
    cout << data[i] << " ";
  }
  return 0;
}