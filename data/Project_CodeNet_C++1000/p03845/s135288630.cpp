#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int t[n];
  for(int i = 0; i < n; ++i) cin >> t[i];
  int m;
  cin >> m;

  for(int i = 0; i < m; ++i){
    int sum = 0;
    int p, x;
    cin >> p >> x;
    for(int j = 0; j < n; ++j){
      if(j == p -1) sum += x;
      else sum += t[j];
    }
    cout << sum << endl;
  }
}