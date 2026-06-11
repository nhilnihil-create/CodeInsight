#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  for (int i = 0; i < N; i++)
    cin >> S[i];
  sort(S.begin(), S.end());
  string Ans;
  for (int i = 0; i < N; i++)
    Ans += S[i];
  cout << Ans << endl;
  return 0;
}