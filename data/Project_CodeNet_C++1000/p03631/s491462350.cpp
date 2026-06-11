#include <iostream>
using namespace std;

int main()
{
  char N[3];
  cin >> N;
  if(N[0] == N[2])
    cout << "Yes";
  else
    cout << "No";
}