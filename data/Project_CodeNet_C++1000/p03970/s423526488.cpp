#include <iostream>
using namespace std;

int main()
{
  int count;
  string name;

  count = 0;
  getline(cin, name);

 /*  if(name[0] != 'C')
  {
    count += 1;
    cout << count << endl;
    if(name[1] != 'O')
    count += 1;
  }
  else if(name[1] != 'O')
  count += 1;

  cout << count << endl;
*/
    if(name[0] != 'C')
    count += 1;
    if(name[1] != 'O')
    count += 1;
    if(name[2] != 'D')
    count += 1;
    if(name[3] != 'E')
    count += 1;
    if(name[4] != 'F')
    count += 1;
    if(name[5] != 'E')
    count += 1;
    if(name[6] != 'S')
    count += 1;
    if(name[7] != 'T')
    count += 1;
    if(name[8] != 'I')
    count += 1;
    if(name[9] != 'V')
    count += 1;
    if(name[10] != 'A')
    count += 1;
    if(name[11] != 'L')
    count += 1;
    if(name[12] != '2')
    count += 1;
    if(name[13] != '0')
    count += 1;
    if(name[14] != '1')
    count += 1;
    if(name[15] != '6')
    count += 1;

    cout << count << endl;

}
