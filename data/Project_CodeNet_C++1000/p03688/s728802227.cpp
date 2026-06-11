#include <iostream>
#include <climits>
using namespace std;

int arr[100005];
int main() {
  int n;
  cin >> n;

  int mn = INT_MAX;
  int mx = 0;
  int freqmn = 0;
  int freqmx = 0;

  for (int i = 1; i <= n; i++){
    cin >> arr[i];
    mn = min (mn, arr[i]);
    mx = max (mx, arr[i]);
  } 

  for (int i = 1; i <= n; i++){
    if (arr[i] == mx) freqmx++;
    else freqmn++;
  }

  if (freqmx == n){
    if ((mx == n-1) || (mx <= n/2))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  else{
    if ((freqmn <= mn) && (mx <= (freqmn + freqmx/2)))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}