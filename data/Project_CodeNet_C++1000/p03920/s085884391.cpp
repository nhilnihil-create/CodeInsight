#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long long i;
  for(i = 1; i <= n; i++)
  {
    if(i*(i-1)/2 < n && n <= i*(i+1)/2)break;
  }
  int cut = i*(i+1)/2-n;
  int j;
  for(j = 1; j <= i; j++)
  {
    if(j != cut)cout << j << endl;
  }
}
