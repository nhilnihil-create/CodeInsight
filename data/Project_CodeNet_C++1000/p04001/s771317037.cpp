#include <bits/stdc++.h>
using namespace std;

string S;
vector<uint64_t> SI;
uint64_t searchsp;

int64_t sumPat(vector<uint64_t> &S, uint64_t F){
  uint64_t e = 1;
  uint64_t sum = 0;
  for(uint64_t i = 0; i < S.size(); i++){
    sum += S.at(i) * e;
    if(((F >> i) & 1) == 1)
      e = 1;
    else
      e *= 10;
  }

  return sum;

}

int main(){

  uint64_t sum=0;

  cin >> S;
  searchsp = pow(2,S.size()-1);

  for(uint64_t i=0;i < S.size();i++){
    SI.push_back((uint64_t)S.at(i) - 48);
  }
  reverse(SI.begin(),SI.end());
  for(uint64_t i=0;i < searchsp;i++){
    sum += sumPat(SI,i);
  }

  cout << sum << endl;

}
