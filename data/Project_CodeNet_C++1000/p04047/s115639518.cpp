#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  n *= 2;
  int arr[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr+n);
  int s = 0;
  for (int i = 0; i < n; i+= 2)
    s += arr[i];
  cout << s << "\n";
  return 0;
}