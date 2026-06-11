#include <iostream>
#include <string>
using namespace std;

int main()
{
  string words[3];
  for(int i = 0; i < 3; ++i)
  {
    cin >> words[i];
  }
  char initisls[3];
  for(int i = 0; i < 3; ++i)
  {
      initisls[i] = words[i].front();
  }
  	cout << initisls << endl;
}
