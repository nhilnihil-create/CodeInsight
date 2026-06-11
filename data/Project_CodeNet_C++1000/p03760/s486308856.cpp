# include <iostream>
using namespace std;

int main() {
  string o, e; cin >> o >> e;
  
  for (int i = 0; i < e.size(); ++i) cout << o[i] << e[i];
  if (o.size() != e.size()) cout << o[o.size() - 1];
  cout << endl;
  
  return 0;
}