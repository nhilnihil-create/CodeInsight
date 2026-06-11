#include <iostream>
#include <vector>
using namespace std;

string getResult(vector<string> &strs, const int strCount, const int strLen){
  for(int i = 0; i < strCount - 1; i++){
    for(int j = strCount - 1; j > i; j--){
      for(int k = 0; k < strLen; k++){
        if(strs[i][k] < strs[j][k]){
          break;
        }
        if(strs[i][k] > strs[j][k]){
          string tmp = strs[i];
          strs[i] = strs[j];
          strs[j] = tmp;
          break;
        }
      }
    }
  }

  string result = "";
  for(string str : strs){
    result += str;
  }
  return result;
}

int main(){
  int N, L;
  cin >> N >> L;

  vector<string> S(N);
  for(int i = 0; i < N; i++){
    cin >> S[i];
  }

  string result = getResult(S, N, L);
  cout << result;
  return 0;
}