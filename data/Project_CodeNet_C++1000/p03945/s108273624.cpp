#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main() {
  string S; cin >> S;
  int N = S.size();
  
  int count =0;
  for (int i =1; i<N; i++) {
    if (S[i] != S[i-1]) count++;
  }
                            
  cout << count << endl;
}