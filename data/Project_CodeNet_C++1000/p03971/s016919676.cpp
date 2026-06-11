#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  int e = 0;
  int f = 0;
  for (int i = 0; i < n; i++)
  {
    if (e < a + b)
    {
      if (s[i] == 'a')
      {
        e++; 
        cout << "Yes" << endl;
      }
      else if (s[i] == 'b' && ++f <= b)
      {
        e++;
        cout << "Yes" << endl;
      }
      else
        cout << "No" << endl;
    }
    else
      cout << "No" << endl;
  }
}