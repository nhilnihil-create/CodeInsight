
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S, Ans;
  cin >> S;
  int N = S.size();
  for (int i = 0; i < N; i++){
    if (S[i] == 'B'){
      if (i != 0){
        for (int j = i; j >= 0; j--){
          if (S[j] != 'B' && S[j] != '?'){
            S[j] = '?';       
            break; 
          }
        }
      }
    }
  }
  for (int i = 0; i < N; i++)
    if (S[i] != '?' && S[i] != 'B')
      Ans += S[i];
  cout << Ans << endl;
  return 0;
}