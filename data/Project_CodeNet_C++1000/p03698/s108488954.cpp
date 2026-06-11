#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  map<char, int> m;
  string S;
  cin >> S;
  for(char c: S){
    if(m.count(c) != 0){
      cout << "no" << endl;
      return 0;
    } else {
      m[c]++;
    }
  }
  cout << "yes" << endl;
}
