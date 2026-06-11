#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  ll h, w;
  cin >> h >> w;

  string c[2*h];

  for(int i = 0; i < 2*h; i += 2){
    cin >> c[i];
    c[i+1] = c[i];
  }

  for(int i = 0; i < 2*h; i++)
    cout << c[i] << endl;
}
