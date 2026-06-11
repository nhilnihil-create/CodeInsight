#include <iostream>
using namespace std;
string magnitude(string & x, string & y)
{
  if( x.size() > y.size() )
  	return "GREATER";
  else if( x.size() < y.size() )
    return "LESS";
  else{
    for(int i = 0; i < x.size(); i++)
      if( x[i] > y[i] )
        return "GREATER";
      else if( x[i] < y[i] )
        return "LESS";
    return "EQUAL";
  }
}
    
int main()
{
  	string a, b;
  	cin >> a >> b;
  	cout << magnitude(a,b);
	return 0;
}