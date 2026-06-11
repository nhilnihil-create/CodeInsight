#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  int g_num = 0, p_num = 0;
  for (int i=0; i<s.size(); i++){
    if (s[i] == 'g') g_num++;
    else p_num++;
  }

  cout << (g_num + p_num) / 2 - p_num << endl;
  return 0;
}