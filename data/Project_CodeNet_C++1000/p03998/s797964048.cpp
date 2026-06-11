#include <iostream>
using namespace std;
int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	int a_index = 0, b_index = -1, c_index = -1;
	char next = a[0];
	while( true )
	{
		if( next == 'a' ){
			a_index++;
			if( a_index == a.size() )
				break;
			next = a[a_index];
		}else if( next == 'b' ){
			b_index++;
			if( b_index == b.size() )
				break;
			next = b[b_index];
		}else{
			c_index++;
			if( c_index == c.size() )
				break;
			next = c[c_index];
		}
	}
	if( next == 'a' ){
		cout << "A";
	}else if( next == 'b' ){
		cout << "B";
	}else{
		cout << "C";
	}
}