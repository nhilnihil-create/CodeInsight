#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(0), rvec(0);
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    if(i%2==0) vec.push_back(x);
    else rvec.push_back(x);
  }
  if(n%2==1){
    for(int i=vec.size()-1; i>=0; --i){
      cout << vec[i] << " ";
    }
    for(int i=0; i<(int)rvec.size(); ++i){
      cout << rvec[i] << " ";
    }
  }else{
    for(int i=rvec.size()-1; i>=0; --i){
      cout << rvec[i] << " ";
    }
    for(int i=0; i<(int)vec.size(); ++i){
      cout << vec[i] << " ";
    }
  }
  cout << endl;
}