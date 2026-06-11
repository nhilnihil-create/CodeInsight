#include <iostream>
#include <algorithm>

using namespace std;

string st;

int const nmax = 50;
int barby[1 + nmax];

int main() {

  int n, s = 1, m = 0, l = 0;
  cin >> n >> m;
  for(int i =1;i <= n;i++){
    cin >> barby[i];
    m += l - s + 1;
  }
  sort(barby+1, barby+n+1);
  for(int i = n;i > n - m ;i--){
    l += barby[i];
  }
  cout << l;
  return 0;
}
