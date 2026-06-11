#include <iostream>
using namespace std;
int main()
{
	string a, b;
  	cin >> a >> b;
  	for(int i = 0; i < b.size(); i++)
      cout << a[i] << b[i];
  	if( b.size() != a.size() )
      cout << a[a.size() - 1];
}