#include <bits/stdc++.h>
#define ll long long
using namespace std;
string niloy(int i){
        string S;
        while(i){
          int d = i%10;
          i /= 10;
          S += d+'0';    
        }
        reverse(S.begin(), S.end());
        return S;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, K;
  cin >> N >> K;
  vector<char> D;
  int ar[10];
  memset(ar, 0, sizeof(ar));
  for (int i = 0; i < K; i++){
    int A;
    cin >> A;
    ar[A]++;
  }
  int Ans;
  for (int i = 0; i <=9; i++)
    if (ar[i] == 0)
      D.push_back(i+'0');
  for (int i = N; ; i++){
    string S = niloy(i);
    bool use = true;
    for (int j = 0; j < S.size(); j++){
      bool ok = false;
      for (int k = 0; k < D.size(); k++){
        if (D[k] == S[j])
          ok = true;
      }
      if (ok == false)
        use = false;
    }
    if (use){
      Ans = i;
      break;   
    }
  }
  cout << Ans << endl;
  return 0;
}