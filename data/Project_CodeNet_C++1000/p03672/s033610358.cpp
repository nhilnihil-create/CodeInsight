#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

string s;

bool check(int erase){
  int n=s.size();
  rep(i,(n-erase)/2){
    if(s.at(i)!=s.at(i+(n-erase)/2)) return false;
  }
  return true;
}

int main(){
  
  cin >> s;
  bool notfound=true;
  int erase=0;
  while(notfound){
    erase+=2;
    if(check(erase)) notfound=false;
  }

  cout << s.size()-erase;
}