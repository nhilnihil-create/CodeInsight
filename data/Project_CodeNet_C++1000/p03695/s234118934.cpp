#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  int col[9] = {0};
  rep(i,n) 
  {
    cin >> a[i];
    if(a[i] >= 3200)
    {
      col[8]++;
    }else
    {
      col[a[i]/400]++;
    }
  }
 
  int ansmin = 0, ansmax = 0;
  rep(i,8)
  {
    if(col[i] > 0)
    {
      ansmin++;
      ansmax++;
    }
  }
  if(col[8] > 0)
  {
    ansmax += col[8];
  }
  if(ansmin == 0) ansmin = 1;
  
  cout << ansmin << " " << ansmax << endl;
  
}