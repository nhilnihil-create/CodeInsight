#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin >> s;

  ll sum = 0;
  for(int bit=0;bit<1<<(s.size()-1);bit++){
    int prev=0;
    for(int i=0;i<s.size();i++){
      if(bit>>i & 1 == 1){
        sum += stoll(s.substr(prev,i+1-prev));
        prev = i+1;
      }
    }
    sum += stoll(s.substr(prev,s.size()));
  }
  cout << sum << endl;
}
