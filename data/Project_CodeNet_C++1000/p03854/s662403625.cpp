#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  bool ans=true;
  while(n>0){
    if(n>4&&s.at(n-5)=='d'&&s.at(n-4)=='r'&&s.at(n-3)=='e'&&s.at(n-2)=='a'
       &&s.at(n-1)=='m'){
     n-=5;
      continue;
    }
     if(n>4&&s.at(n-5)=='e'&&s.at(n-4)=='r'&&s.at(n-3)=='a'&&s.at(n-2)=='s'
       &&s.at(n-1)=='e'){
     n-=5;
      continue;
    }
     if(n>6&&s.at(n-7)=='d'&&s.at(n-6)=='r'&&s.at(n-5)=='e'&&s.at(n-4)=='a'
       &&s.at(n-3)=='m'&&s.at(n-2)=='e'&&s.at(n-1)=='r'){
     n-=7;
      continue;
    }
     if(n>5&&s.at(n-6)=='e'&&s.at(n-5)=='r'&&s.at(n-4)=='a'&&s.at(n-3)=='s'
       &&s.at(n-2)=='e'&&s.at(n-1)=='r'){
     n-=6;
      continue;
    }
    ans=false;
    break;
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}