#include<bits/stdc++.h>
using namespace std;


int main(){

  int64_t N,tmp,num;
  vector<int64_t> a;
  
  cin >> N;
  for(int64_t i=0;i<3*N;i++){
    cin >> tmp;
    a.push_back(tmp);
  }
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  num=0;
  for(int64_t i=0;i<N;i++){
    num += a.at(2 * i + 1);
  }

  cout << num << endl;
}
