#include <iostream>
using namespace std;

int main() {
    string stra;
    int a,z,x;
    cin >> stra;
    a = stra.find("A");
    z = stra.rfind("Z");
    z=z+1;
    x=z-a;
    cout << x << endl;
}