#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  long long int n,l,i,j;
  cin >> n >> l;
  vector <string> str(n);
  string answer;
  for(i=0;i<n;i++)
  {
    cin >> str[i];
  }
  sort(str.begin(), str.end());
  for(i=0;i<n;i++)
  {
    answer = answer + str[i];
  }
  cout << answer;
  return 0;
}