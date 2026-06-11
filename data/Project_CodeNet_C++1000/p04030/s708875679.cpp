#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> answer;
  string s;
  cin >> s;
  for (long unsigned int i = 0; i < s.size(); i++){
    if(s.at(i)=='0'){
      answer.push_back(0);
    }
    else if(s.at(i)=='1'){
      answer.push_back(1);
    }
    else if((s.at(i)=='B')&&(answer.size()>0)){
      answer.pop_back();
    }
  }
  for (long unsigned int i = 0; i < answer.size(); i++){
    cout << answer.at(i);
  }
}