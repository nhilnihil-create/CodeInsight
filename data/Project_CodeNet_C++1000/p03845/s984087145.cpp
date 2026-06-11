#include <iostream>
using namespace std;
int main()
{
  int n;
  long long int sum = 0;
  cin >> n;
  int tab[n];
  for(int i = 0; i < n; i++)
  {
    cin >> tab[i];
    sum += tab[i];
  }
  int m, p, t;
  cin >> m;
  for(int i = 0; i < m; i++)
  {
    cin >> p  >> t;
    cout << sum - tab[p-1] + t << "\n";
  }
}