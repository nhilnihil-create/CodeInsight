#include <bits/stdc++.h>
using namespace std;

string func(int N, vector<int> vec, set<int> S) {
  
  if (S.size() > 2) return "No";
  
  else if (S.size() == 2) {
    
    int a = *rbegin(S);
    S.erase(a);
    int b = *rbegin(S);
    
    if (a-b != 1) return "No";
    
    int i = 0, j = 0;
    
    for (int k = 0; k < N; k++) {
      if (vec[k] == a) i++;
      else j++;
    }
    
    if ((a-j)*2 <= i && j <= b) return "Yes";
    else return "No";
    
  }
  
  else {
    
    int a = *rbegin(S);
    if (a == N - 1 || N >= 2*a) return "Yes";
    else return "No";
    
  }
  
}

int main() {

  int N;
  cin >> N;
  
  vector<int> vec(N);
  set<int> S;
  
  for (int i = 0; i < N; i++) {
    cin >> vec[i];
    S.insert(vec[i]);
  }
  
  cout << func(N, vec, S) << endl;
}