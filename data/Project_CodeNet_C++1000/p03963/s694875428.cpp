#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int n, k;
  scanf ("%d%d", &n, &k);
  int x = k * pow(k-1, n-1);
  printf ("%d\n", x);
}