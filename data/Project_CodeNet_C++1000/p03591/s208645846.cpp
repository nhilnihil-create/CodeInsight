#include <iostream>
using namespace std;

int main()
{
  string name;
  getline(cin, name);

  if(name[0] == 'Y')
  {
    if(name[1] == 'A')
    {
      if(name[2] == 'K')
      {
        if(name[3] == 'I')
        {
          cout << "Yes" << endl;
        }
        else
        cout << "No" << endl;
      }
      else
      cout << "No" << endl;
    }
    else
    cout << "No" << endl;
  }
  else
  cout << "No" << endl;
}
