#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
int x , t;
cin >> x >> t;
int k = x - t;
if(k >= 0)cout << k << endl;
else cout << 0 << endl;
}