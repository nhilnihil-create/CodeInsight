#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  char w[101];
  cin >> w;

  char abc[] = "abcdefghijklmnopqrstuvwxyz";
  int ab[strlen(abc)];
  for(int i = 0; i < strlen(abc); i++) ab[i]=0;

  for (int i = 0; i < strlen(w); i++) {
    for (int j = 0; j < strlen(abc); j++) {
      if (w[i] == abc[j]) ab[j]++;
    }
  }
  bool key = true;
  for (int i = 0; i < strlen(abc); i++) {
    if (ab[i] % 2 != 0) {key = false; break; }
  }
  if (key)
  cout << "Yes" << endl;
  else
  {
    cout << "No" << endl;
  }
  
}