#include<iostream>
#include<string>
using namespace std;
 
int main() {
	string buff;
	getline(cin, buff);
	string add = " ";
	buff.insert(4, " ");
	cout << buff << endl;
}