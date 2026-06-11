#include "bits/stdc++.h"
using namespace std;
int main() {
	string str;
	cin >> str;
	stack <char> x;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == 'S') 
          x.push(str.at(i));
		else {
			if(x.empty()) 
              x.push(str.at(i));
			else if(x.top() == 'T') 
              x.push(str.at(i));
			else x.pop();
		}
	}
	cout <<x.size();
  return 0;
}
