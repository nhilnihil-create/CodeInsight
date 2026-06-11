#include<iostream>
#include<string>
#include <vector>
using namespace std;
int main(){
  string S;
  cin >> S;
  long long sum=0;
  int l = S.length();
  for(int bit=0; bit< (1<<(l-1)); ++bit){
    vector<int> tmp;
    for(int i=0; i<l-1; ++i){
      if(bit & (1<<i)){
        tmp.push_back(i);
      }
    }
    
    if(tmp.size() == 0) sum += stol(S);
    else{
      sum += stoi(S.substr(0, tmp[0]+1));
      for(int i=1; i<tmp.size(); ++i){
        sum += stol(S.substr(tmp[i-1]+1, tmp[i]-tmp[i-1]));
      }
      sum += stol(S.substr(tmp[tmp.size()-1]+1));
    }
  }
  cout << sum << endl;
  return 0;
}