#include <iostream>
#include <string>
using namespace std;

int main (){
 string s;
 cin >> s;
 size_t size = s.length();

 cout << s[0] << size-2 << s[size-1] << endl;


}