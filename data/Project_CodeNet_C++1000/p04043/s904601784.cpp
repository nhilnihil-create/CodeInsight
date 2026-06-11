#include<bits/stdc++.h>

using namespace std;

int main()
{
 vector<int > a(3);
  cin >> a[0] >> a[1] >> a[2];
  
  sort(a.begin(), a.end());
  if(a[0] == 5 && a[1] == 5 && a[2] == 7)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
