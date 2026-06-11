#include <iostream>
#include <string>

using namespace std;

string s,t;
int N;
long long mod = 1e9 + 7;
long long p = 1;

int main(){
  cin >> N;
  cin >> s;
  cin >> t;
  int ptr = 0;
  if(s[0] == t[0]){
    p *= 3;
    ptr += 1;
  }else{
    p *= 6;
    ptr += 2;
  }
  while(ptr < N){
    if(s[ptr]==t[ptr]){
      if(s[ptr-1]==t[ptr-1]) p *= 2;
      ptr++;
    }else{
      if(s[ptr-1]==t[ptr-1]) p *= 2;
      else p *= 3;
      ptr += 2;
    }
    p %= mod;
  }
  cout << p << endl;
  return 0;
}


