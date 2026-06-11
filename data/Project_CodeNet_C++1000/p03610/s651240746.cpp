#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  string s;
  cin >> s;
  ll L = (s.size() + 1)/2;
  for(int i = 0; i < L; i++){
    cout << s.at(2*i);
  }
  cout << endl;
}
