#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N = 0,A = 0,B = 0,countA = 0,countB = 0;
  string s;
  cin >> N >> A >> B >> s;
  rep(i,N){
    if(countA + countB >= A + B){
      cout << "No" << endl;
      continue;
    }
    if(s.at(i) == 'c'){
      cout << "No" << endl;
    }
    if(s.at(i) == 'a'){
      if(countA + countB <= A + B){
        cout << "Yes" << endl;
        countA++;
      }
      else{
        cout << "No" << endl;
      }
    }
    if(s.at(i) == 'b'){
      if(countA + countB <= A + B && countB < B){
      cout << "Yes" << endl;
      countB++;
      }
      else{
        cout << "No" << endl;
      }
    }
  }
}