#include<bits/stdc++.h>
using namespace std;

long long calc(string s){
  int N = s.size();
  long long ret = stoll(s);
  
  //recursive step
  for(int i=1;i<N;i++){
    string sl = s.substr(0,i);
    string sr = s.substr(i,N-i);
    ret += stoll(sl)*pow(2,sr.size()-1);
    ret += calc(sr);
  }
  
  return ret;
}

int main(){
  string s;
  cin >> s;
  cout << calc(s) << endl;
  
  return 0;
}