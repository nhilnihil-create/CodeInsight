#include <bits/stdc++.h>
using namespace std;

int main() {
  	locale l = locale::classic();
  
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
  	cout << toupper(s1.at(0),l) << toupper(s2.at(0),l) << toupper(s3.at(0),l) << endl;
}