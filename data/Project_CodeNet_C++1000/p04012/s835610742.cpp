#include<bits/stdc++.h>
using namespace std;

int main(){
  string w;
  cin >> w;
  vector<int> vec(26);
  for(int i = 0; i < w.size(); i++){
  vec[w[i]-'a'] += 1;
  }
  for(int i = 0; i < 26; i++){
    if(vec[i] % 2 != 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
