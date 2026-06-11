#include <bits/stdc++.h>

using namespace std;

int main() {
  	string s;
  	cin >> s;
  	int n = s.size();
    bool even = 0;
  	if (s[0] != s[n - 1])
    	even = 1;
  	if (even == !(n % 2))
    	cout << "Second";
  	else
      	cout << "First";
}