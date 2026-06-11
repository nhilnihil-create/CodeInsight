#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  string s;
  cin >> s;
  int slen = s.size();
  vector<int> result(26);
 
  //cout << slen;
  for(int i = 0; i < slen; i++)
  {
    for(int j = 0; j < 26; j ++)
    {
      if(s[i] == 'a' + j)
      {
        int r = 'a' + j;
        result[j] = 1;
        continue;
      }
    }
  }
  /*for(int i = 0; i < 26; i++)
  {
    cout << i << ": " << result[i] << endl;
  }*/
  for(int i = 0; i < 26; i++)
  {
    if(result[i] == 0)
    {
      char c = 'a' + i;
      cout << c << endl;
      return (0);
    }
  }
  cout << "None" << endl;
}