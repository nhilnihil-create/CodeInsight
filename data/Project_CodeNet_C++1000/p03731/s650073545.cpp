#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,T;
  cin >> n >> T;
  vector<long long> t(n);
  long long ans = 0;
  
  for(auto i=0;i<n;i++){
    cin >> t.at(i);
  }
  vector<long long> endtime(n+1);
  endtime.at(0) = 0;
  for(auto i=0;i<n;i++){
    //long long dt = t.at(i+1)-t.at(i);
    if(endtime.at(i)>t.at(i)){
      endtime.at(i+1) = t.at(i) + T;
      ans += (endtime.at(i+1)-endtime.at(i));
    }
    else{
      ans +=T;
      endtime.at(i+1) = t.at(i) + T;
    }
  }
  cout << ans<< endl;
}
