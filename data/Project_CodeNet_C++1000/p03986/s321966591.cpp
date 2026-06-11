#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

vector <char> m;
int main() {
  string n;
  cin >> n;

  ll f = n.length();
  ll res = f;
  for (ll i=0; i< f; i++){
    if (n[i] == 'S'){
      m.push_back(n[i]);
    }
    else{
      if (!m.empty() && m.back() == 'S'){
        m.pop_back();
      }
      else{
        m.push_back(n[i]);
      }
    }
  }

  cout << m.size() << endl;
  return 0;
}