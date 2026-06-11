#include <iostream>
using namespace std;

int main()
{
  int card1, card2;

  cin >> card1 >> card2;

  if(card1 < card2)
  {
    if (card1 == 1 && card2 != 1)
    {
      cout << "Alice" << endl;
    }
    else
    cout << "Bob"<< endl;
  }
  else if(card1 == card2)
  {
    cout << "Draw" << endl;
  }
  else if (card1 != 1 && card2 ==1)
  {
    cout << "Bob" << endl;
  }
  else
  cout << "Alice" << endl;
}
