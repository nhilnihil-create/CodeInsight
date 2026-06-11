#include<bits/stdc++.h>
using namespace std;
int main() {
  char a, b; cin >> a >> b; map<char, char> d; d['H'] = 'D'; d['D'] = 'H';
  cout << ((a == 'H') ? b : d.at(b)) << endl;
}
