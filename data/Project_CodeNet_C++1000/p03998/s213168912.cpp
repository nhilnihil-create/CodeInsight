#include <iostream>
#include <string>

using namespace std;

int main()	{
  	string a, b, c;
  	cin >> a >> b >> c;
  	char play;
  	char to_play = 'a';
  	while (1)	{
		switch(to_play)	{
          case 'a': if (a.empty()) { cout << "A" << endl; return 0;}
            		to_play = a[0];
            		a.erase(a.begin());
            		break;
          case 'b': if (b.empty()) { cout << "B" << endl; return 0;}
            		to_play = b[0];
            		b.erase(b.begin());
            		break;
          case 'c': if (c.empty()) { cout << "C" << endl; return 0;}
            		to_play = c[0];
            		c.erase(c.begin());
            		break;
        }
    }
	return 0;
}