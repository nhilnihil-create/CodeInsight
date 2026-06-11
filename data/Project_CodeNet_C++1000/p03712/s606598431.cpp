#include <iostream>
#include <string>

using namespace std;

int const NMAX = 100;
char v[1 + NMAX][1 + NMAX];

int main() {

  int n, m;
  char inp;
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      cin >> v[i][j];
    }
  }
  for(int i = 0;i <= m + 1;i++){
    cout << "#";
  }
  cout << '\n';
  for(int i = 1;i <= n;i++){
    cout << "#";
    for(int j = 1;j <= m;j++){
      //cin >> inp;
      cout << v[i][j];
    }
    cout << "#\n";
  }
  for(int i = 0;i <= m + 1;i++){
    cout << "#";
  }
  return 0;
}
