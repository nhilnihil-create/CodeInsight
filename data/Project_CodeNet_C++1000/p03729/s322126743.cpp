#include<iostream>
using namespace std;
int main()
{
  string a,b,c;
  
  cin >> a >> b  >> c;
 	int lenA,lenB,lenC;
  	lenA = a.size();
    lenB = b.size();
    lenC = c.size();
	if(a.at(lenA-1) == b.at(0) && b.at(lenB-1)== c.at(0))
  		cout << "YES";
  		else cout << "NO";
  //cout << (a + b + c) << " " << s ;
  
}
  
