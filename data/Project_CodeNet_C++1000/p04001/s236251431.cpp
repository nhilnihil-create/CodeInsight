#include <bits/stdc++.h>
using namespace std;
int64_t keisan(vector<bool> &p,vector<int> &s){
  int64_t j=0;
  int64_t k=s.at(0);
  for(int i=1;i<s.size();i++){
    if(p.at(i)){
      j+=k;
      k=s.at(i);
    }
    else{
      k=k*10+s.at(i);
    }
  }
  j+=k;
  return j;
}

void tasu(vector<bool> &p,vector<bool> &bo,int k,vector<int> &s,int64_t &j){
  if(k==p.size()){
    j+=keisan(p,s);
    return;
  }
  for(bool i:bo){
    p.at(k)=i;
    tasu(p,bo,k+1,s,j);
  }
}
    

int main() {
  int64_t S;
  cin >> S;
  vector<int> s(0);
  for(;S>0;S/=10)
    s.push_back(S%10);
  reverse(s.begin(),s.end());
  vector<bool> p(s.size(),false),bo={false,true};
  int64_t j=0;
  tasu(p,bo,1,s,j);
  cout << j << endl;
}