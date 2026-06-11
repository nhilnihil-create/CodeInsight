#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  string O,E;
  cin >> O;
  cin >> E;
  
  string ans = "";
  for(int i = 0; i < O.size(); i++){
    ans += O[i];
    if(i < E.size()) ans += E[i];
  }
  cout << ans << endl;
}

