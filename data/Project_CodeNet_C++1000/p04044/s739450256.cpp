#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, l; 
  cin >> n >> l;
  
  vector<string > a(n);
  for(auto &it: a)
    cin >> it;
  
  sort(a.begin(), a.end());
  string res = "";
  for(auto it: a)
    res += it;
  
  cout << res;
  return 0;
}