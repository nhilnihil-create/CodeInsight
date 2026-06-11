#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  
  string S;
  cin >> S;
  map<char,int> m;
  for(char c: S){
    m[c]++;
  }
  
  bool flg = true;
  if(m.count('N') != 0 && m.count('S') == 0)
    flg &= false;
  if(m.count('S') != 0 && m.count('N') == 0)
    flg &= false;
  if(m.count('W') != 0 && m.count('E') == 0)
    flg &= false;
  if(m.count('E') != 0 && m.count('W') == 0)
    flg &= false;
  
  cout << (flg ? "Yes" : "No") << endl;
  
  
}

