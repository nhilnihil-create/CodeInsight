#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  string S1,S2;
  cin >> S1;
  cin >> S2;
  string pattern = "";

  int index = 0;
  while(index < N){
    if(S1[index] == S2[index]){
      index++;
      pattern += "A";
    } else {
      index += 2;
      pattern += "B";
    }
  }
  ll ans = 1;
  if(pattern[0] == 'A') ans = 3;
  else ans = 6;

  for(int i = 1; i < pattern.size(); i++){
    if(pattern[i-1] == 'A' && pattern[i] == 'A'){
      ans *= 2;
    }
    if(pattern[i-1] == 'A' && pattern[i] == 'B'){
      ans *= 2;
    }
    if(pattern[i-1] == 'B' && pattern[i] == 'A'){
      ans *= 1;
    }
    if(pattern[i-1] == 'B' && pattern[i] == 'B'){
      ans *= 3;
    }
    ans %= MOD;
  }

  cerr << pattern << endl;
  cout << ans << endl;
}

