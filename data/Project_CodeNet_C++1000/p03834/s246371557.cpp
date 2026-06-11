#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int Q=1000000007;

int main(){
  string S;cin >> S;
  for(int i=0;i<S.size();i++){
    if(S[i]==','){
      cout << " ";
    }else{
      cout << S[i];
    }
  }
  cout << endl;
}