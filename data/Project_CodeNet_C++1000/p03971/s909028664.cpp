#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;

  int cnt=0, cnt_i=0;

  string s;
  cin >> s;

  for(int i=0; i<n; i++)
  {
    if(s.at(i)=='a')
    {
      if(cnt<a+b){
        cout << "Yes" << endl;
        cnt++;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    else if(s.at(i)=='b')
    {
      if(cnt<a+b && cnt_i<b)
      {
        cout << "Yes" << endl;
        cnt++, cnt_i++;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
