#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
int a , b , c , d;
cin >> a >> b >> c >> d;
cout << max(a * b , c * d) << endl;
}