#include <iostream>
#include <string>

using namespace std;

int zerolength(string a, string b, string c)	{
  	int res = 0;
	if (a.length() == 0)
      	res++;
 	if (b.length() == 0)
      	res++;
 	if (c.length() == 0)
      	res++;
  	return res;
}

int main()	{
	string a, b, c;
  	char next;
  	cin >> a >> b >> c;
  	next = a[0];
  	a.erase(a.begin());
  	while (1)	{
      	switch(next)	{
          case 'a': if (a.length() == 0)	{
          				cout << "A" << endl;
            			return 0;
          			}
            		next = a[0];
            		a.erase(a.begin());
            		break;
          case 'b': if (b.length() == 0)	{
          				cout << "B" << endl;
            			return 0;
          			}
            		next = b[0];
            		b.erase(b.begin());
					break;
          case 'c': if (c.length() == 0)	{
            			cout << "C" << endl;
            			return 0;
          			}
            		next = c[0];
            		c.erase(c.begin());
            		break;
        }
    }
  	
  	return 0;
}