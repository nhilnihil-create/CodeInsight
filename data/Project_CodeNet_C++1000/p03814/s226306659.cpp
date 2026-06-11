#include <bits/stdc++.h>
using namespace std;


int main()
{
  string s;
  cin >> s;

  int min = 200100;
  int max = -1;
  for (int i = 0; i < s.size(); i++)
  {
    if(s.at(i) == 'A'){
        
        if(min > i){
          min = i;
        }
      }
    else if (s.at(i) == 'Z')
    {
      if(max < i){
        max = i;
      }
    }
  }
  int ans = max - min + 1;
  cout << ans << endl;
}
