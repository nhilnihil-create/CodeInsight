#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> d(k);
  for(int i=0;i<k;i++) cin >> d.at(i);
  sort(d.begin(),d.end());
  
  for(int i=n;i<=100000;i++){
    int m=i;
    int ans=1;
    while(m>0){
      if(binary_search(d.begin(),d.end(),m%10)){
        ans=0;
        break;
      }
      else{
        m/=10;
      }
    }
    if(ans){
      cout << i << endl;
      i=100000;
    }
  }
}