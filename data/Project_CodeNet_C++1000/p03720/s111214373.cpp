#include <iostream>
#include <string>

using namespace std;

int const NMAX = 50;
int freq[1 + NMAX];

int main() {

  int n, g = 0, GGY = 0, GGX = 0;
  cin >> n >> g;
  for(int i = 1;i <= g;i++){
    cin >> GGX >> GGY;
    freq[GGX]++;
    freq[GGY]++;
  }
  for(int i = 1;i <= n;i++){
    cout << freq[i] << '\n';
  }
  return 0;
}
