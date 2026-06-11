#include <bits/stdc++.h>
using namespace std;

int main() {
  long long quart,half,one,two;
  long long kounyuL;
  long long kekka = 0;
  long long oneL = 0;
  
  cin >> quart >> half >> one >> two;
  cin >> kounyuL;
  
  oneL = min({quart * 4, half * 2, one});
  kekka = min(oneL * kounyuL, two * (kounyuL / 2) + oneL * (kounyuL % 2));
  cout << kekka;
}
