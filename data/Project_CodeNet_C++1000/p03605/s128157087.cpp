#include <iostream>
using namespace std;

int main()
{
 	char N[2];
  	cin >> N;
  	if(N[0] == '9')
      cout << "Yes";
  	else if(N[1] == '9')
      cout << "Yes";
  	else
      cout << "No";
}