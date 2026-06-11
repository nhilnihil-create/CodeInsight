#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int frec[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    frec[a]++;
  }
  int smin = 0, smax = 0;
  for(int i = 1;i <= n; i++) {
    if(smin == 0 && 0 < frec[i])
      smin = i;
    if(0 < frec[i])
      smax = i;
  }
  if(smin == smax){
    if(smin == n - 1)
      cout << "Yes";
    else if(smin <= n / 2)
      cout << "Yes";
    else
      cout << "No";
  } else if(frec[smin] + frec[smax] < n){
    cout << "No";
  } else if(smin == smax - 1){
    if(frec[smin] + 1 <= smax && smax <= frec[smin] + frec[smax] / 2)
      cout << "Yes";
    else
      cout << "No";
  } else
    cout << "No";
  return 0;
}
