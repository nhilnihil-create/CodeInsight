#include <iostream>
#include <string>
using namespace std;

int main()
{
  static const int numberOfWords = 3;
  string words[numberOfWords];
  for(int i = 0; i < numberOfWords; ++i)
  {
    cin >> words[i];
  }
  char initisls[numberOfWords];
  for(int i = 0; i < 3; ++i)
  {
      initisls[i] = words[i].front();
  }
  	cout << initisls << endl;
}
