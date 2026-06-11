
#include<iostream>
using namespace std;
int main() {
  int n,k;
  cin>>n>>k;
  int j = 0;
  for(int i = 0;i < n;i++){
    int l = 0,x = 0;
    cin>>x;
    l = (k - x) * 2;
    x *= 2;
    if(x < l){
      j += x;
    }else{
      j += l;
    }
  }
  cout<<j<<endl;
  return 0;
  }