#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
int a , b;
cin >> a >> b;
if(a == 1)a += 13;
if(b == 1)b += 13;
if(a == b)cout << "Draw" << endl;
else if(a > b)cout << "Alice" << endl;
else cout << "Bob" << endl;
}