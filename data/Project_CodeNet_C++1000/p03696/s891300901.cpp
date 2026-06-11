#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  string S;
  cin >> S;

  int right = 0;
  int left = 0;
  string left_ans = "";
  for(int i = 0; i < S.size(); i++){
    if(S[i] == '('){
      left++;
    } else { 
      if(left > 0){
        left--;
      } else { 
        left_ans += "(";
      }
    }
  }

  right = 0;
  left = 0;
  string right_ans = "";
  for(int i = S.size()-1; i >= 0; i--){
    if(S[i] == ')'){
      right++;
    } else { 
      if(right > 0){
        right--;
      } else { 
        right_ans += ")";
      }
    }
  }

  cout << left_ans + S + right_ans << endl;

}
