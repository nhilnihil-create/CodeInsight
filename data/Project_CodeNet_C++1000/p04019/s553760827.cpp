#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  bool n=false;
  bool m=false;
  bool w=false;
  bool e=false;
  rep(i,s.size()){
    if(s.at(i)=='N'){
      n=true;
    }
    else if(s.at(i)=='S'){
      m=true;
    }
    else if(s.at(i)=='W'){
      w=true;
    }
    else if(s.at(i)=='E'){
      e=true;
    }
  }
  if((n&&m&&w&&e)||(n&&m&&!w&&!e)||(!n&&!m&&w&&e)){
    cout<<"Yes"<<endl;
  }
  
  else{
    cout<<"No"<<endl;
  }
  
 
}


