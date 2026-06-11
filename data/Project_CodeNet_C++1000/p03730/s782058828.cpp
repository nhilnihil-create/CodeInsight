#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  
  vector<bool> pass(B, false);
  int num = 0;
  while (true){
    int tar = (num * A) % B;
    if (tar == C){
      cout << "YES" << endl;
      exit(0);
    }
    
    if (pass.at(tar) == true){
      cout << "NO" << endl;
      exit(0);
    }
    
    pass.at(tar) = true;
    num++;
  }
}