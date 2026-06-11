#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string s;
  cin >> s;
  while(s.size()!=0){
    if(s.find("eraser")==string::npos){
      break;
    }
    else{
      int k=s.find("eraser");
      s.erase(k,6);
    }
  }
  while(s.size()!=0){
    if(s.find("erase")==string::npos){
      break;
    }
    else{
      int k=s.find("erase");
      s.erase(k,5);
    }
  }
  while(s.size()!=0){
    if(s.find("dreamer")==string::npos){
      break;
    }
    else{
      int k=s.find("dreamer");
      s.erase(k,7);
    }
  }
  while(s.size()!=0){
    if(s.find("dream")==string::npos){
      break;
    }
    else{
      int k=s.find("dream");
      s.erase(k,5);
    }
  }
  if(s.size()==0)
  cout << "YES" << endl;
  else
  cout << "NO" << endl;
}

