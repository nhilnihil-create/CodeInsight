#include <iostream>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    char aa = a.at(0)-32;
    char bb = b.at(0)-32;
    char cc = c.at(0)-32;
    cout << aa << bb << cc << endl;

    return 0;
}