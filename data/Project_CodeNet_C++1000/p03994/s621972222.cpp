#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int64_t K;
  cin >> s >> K;
  int diff;
  for(int i=0;i<s.size()-1;i++){
    if(s.at(i)=='a'){
      cout << s.at(i);
    }else{
      diff='z'-s.at(i)+1;
      if(K>=diff){
        cout << 'a';
        K-=diff;
      }else{
        cout << s.at(i);
      }
    }
  }
  K%=26;
  cout << static_cast<char>(((s.back()-'a')+K)%26+'a') << endl;
  return 0;
}
