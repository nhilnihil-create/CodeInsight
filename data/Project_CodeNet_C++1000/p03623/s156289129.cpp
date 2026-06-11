#include <bits/stdc++.h>
using namespace std;

int main() {

	int a,b,c;
  	cin >> a >> b >> c;
  	b = abs(a-b);
  	c = abs(a-c);
  	if(b > c)cout << "B" << endl;
  	else cout << "A" << endl;
      
}

   
