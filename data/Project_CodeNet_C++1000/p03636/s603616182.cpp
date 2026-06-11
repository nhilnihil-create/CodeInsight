#include <iostream>
using namespace std;

int main() {
    string stra;
    int x,y,z;
    cin >> stra;
    x=stra.length();
    z=x-2;
    y=x-1;
    cout << stra[0] << z << stra[y] << endl;
}